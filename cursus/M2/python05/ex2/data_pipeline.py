from abc import ABC, abstractmethod
from typing import Any, Protocol


class DataProcessor(ABC):
    """Base abstract data processor with common interface."""

    def __init__(self) -> None:
        # cola interna de datos ya ingeridos (como strings)
        self._buffer: list[tuple[int, str]] = []
        # cuántos elementos hemos procesado (para rank)
        self._processed_count: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Return True if this processor can handle 'data'."""
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        """Process and store 'data'.
        Must raise an exception if 'data' is invalid for this processor.
        """
        pass

    def output(self) -> tuple[int, str]:
        """Extract the oldest stored item and its processing rank."""
        # extraer el mas antiguo (cola FIFO)
        return self._buffer.pop(0)


class NumericProcessor(DataProcessor):
    """Processor for numeric data (int, float, list of them)."""

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, (int, float)):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[int | float] | Any) -> None:
        # si no validan antes, aqui debemos lanzar excepcion si es invalido
        if not self.validate(data):
            raise ValueError("Improper numeric data")

        # normalizar a lista de numeros
        if not isinstance(data, list):
            items = (self._processed_count, str(data))
            self._buffer.append(items)
            self._processed_count += 1
        else:
            # convertir a strings y guardar en buffer
            for item in data:
                tup = (self._processed_count, str(item))
                self._buffer.append(tup)
                self._processed_count += 1


class TextProcessor(DataProcessor):
    """Processor for text data (str and list[str])."""

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise TypeError("Improper text data")
        if not isinstance(data, list):
            item_tuple: tuple[int, str] = (self._processed_count, str(data))
            self._buffer.append(item_tuple)
            self._processed_count += 1
        else:
            for item in data:
                tup: tuple[int, str] = (self._processed_count, str(item))
                self._buffer.append(tup)
                self._processed_count += 1


class LogProcessor(DataProcessor):
    """Processor for log entries (dict[str, str] and list of them)."""
    def _checking(self, data: dict[str, str]) -> bool:
        for key, value in data.items():
            if not isinstance(key, str) or not isinstance(value, str):
                return False
        return True

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return self._checking(data)
        if isinstance(data, list):
            for item in data:
                if not self._checking(item):
                    return False
            return True
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise TypeError("Improper log data")
        if isinstance(data, dict):
            text = data["log_level"] + ": " + data["log_message"]
            tup = (self._processed_count, text)
            self._buffer.append(tup)
            self._processed_count += 1
        elif isinstance(data, list):
            for item in data:
                text = item["log_level"] + ": " + item["log_message"]
                tup = (self._processed_count, text)
                self._buffer.append(tup)
                self._processed_count += 1


class ExportPlugin(Protocol):
    """Protocol for export plugins used by the DataStrteam output pipeline."""
    def process_output(self, data: list[tuple[int, str]]) -> None:
        """Process a batch of (rank, value) tuples from a DataProcessor."""


class DataStream:
    """Adaptive stream processor that routes data to the right DataProcessor"""

    def __init__(self) -> None:
        # Lista de processadores registrados (NumericProcessor, TextProcessor,
        # LogProcessor, etc.)
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        """Register a new data processir to handle elements in the stream."""
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        """Analyze each element and send it to an appropiate processor."""
        for element in stream:
            handled = False

            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    handled = True
                    break   # ya hemos encontrado un procesador valido de los 3

            if not handled:
                print("DataStream error - Can't process element in stream:"
                      f" {element}")

    def print_processors_stats(self) -> None:
        """Print statistics about each registered processor."""
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processors found, no data")
            return

        for proc in self._processors:
            total = proc._processed_count
            remaining = len(proc._buffer)
            name = proc.__class__.__name__

            print(f"{name}: total {total} items processed, remaining"
                  f" {remaining} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        """Consume nb elements from each processor and expot them via the
        plugin."""
        for proc in self._processors:
            batch: list[tuple[int, str]] = []

            # Consumir hasta nb elementos, o menos si no hay tantos
            for _ in range(nb):
                if not proc._buffer:
                    break   # no quedan mas datos en este procesador
                item = proc.output()    # (rank, value)
                batch.append(item)

            if batch:
                plugin.process_output(batch)


class CsvExportPlugin:
    """CSV export plugin: prints comma-separated values."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        # Ignoramos rank, nos quedamos solo con los valores
        values = [value for _,  value in data]
        line = ",".join(values)
        print(f"CSV Output:\n{line}")


class JsonExportPlugin:
    """JSON export plugin: prints a JSON object with item_i keys."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        # Construimos un dict tipo {"item_3": "42", ...}
        items: dict[str, str] = {}
        for rank, value in data:
            key = f"item_{rank}"
            items[key] = value

        # Convertimos ese dict a una cadena JSON sencilla
        # No usamos json.dumps porque el ejercicio dice crear las cadenas a
        # mano.! no haks!!
        parts = [f"\"{key}\":\"{value}\"" for key, value in items.items()]
        json_str = "{" + ",".join(parts) + "}"

        print(f"JSON Output:\n{json_str}")


def main() -> None:
    stream = DataStream()

    print("Initialize Data Stream...", end="\n\n")
    stream.print_processors_stats()
    print()

    num = NumericProcessor()
    txt = TextProcessor()
    log = LogProcessor()

    stream.register_processor(num)
    stream.register_processor(txt)
    stream.register_processor(log)

    first_batch = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead"
            },
            {
                "log_level": "INFO",
                "log_message": "User wili s connected"
            },
        ],
        42,
        ["Hi", "five"],
    ]

    print(f"Send first batch of data on stream: {first_batch}", end="\n\n")
    stream.process_stream(first_batch)
    stream.print_processors_stats()
    print()

    csv_plugin = CsvExportPlugin()
    print("Send 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, csv_plugin)
    print()
    stream.print_processors_stats()
    print()

    second_batch = [
        21,
        [
            "I love AI",
            "LLMs are wonderful",
            "Stay healthy"
        ],
        [
            {
                "log_level": "ERROR",
                "log_message": "500 server crash"
            },
            {
                "log_level": "NOTICE",
                "log_message": "Certificate expires in 10"
            },
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello",
    ]

    print(f"Send another batch of data: {second_batch}", end="\n\n")
    stream.process_stream(second_batch)
    stream.print_processors_stats()
    print()

    json_plugin = JsonExportPlugin()
    print("Send 5 processed data from each processors to a JSON plugin:")
    stream.output_pipeline(5, json_plugin)
    print()
    stream.print_processors_stats()


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===", end="\n\n")
    main()
