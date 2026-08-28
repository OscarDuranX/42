from abc import ABC, abstractmethod
from typing import Any


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


class DataStream:
    """Adaptive stream processor that routes data to the right DataProcessor"""

    def __init__(self) -> None:
        # Lista de processadores registrados (NumericProcessor, TextProcessor
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


def main() -> None:
    # Inicializar DataStream
    stream = DataStream()
    print("Initialize Data Stream...")
    stream.print_processors_stats()
    print()

    # Registrar solo NumericProcessor
    num = NumericProcessor()
    stream.register_processor(num)
    print("Registering Numeric Processor", end="\n\n")

    # primer batch de datos
    batch = [
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
    print(f"Send frist batch of data on stream: {batch}")

    stream.process_stream(batch)
    stream.print_processors_stats()
    print()
    # Registrar otros procesadores
    txt = TextProcessor()
    log = LogProcessor()
    stream.register_processor(txt)
    stream.register_processor(log)
    print("Registering other data processors")

    print("Send the same batch again")
    stream.process_stream(batch)
    stream.print_processors_stats()
    print()

    # Consumir algunos elementos con output()
    print("Consume some elements from the date processors: Numeric 3, Text 2,"
          " Log 1")
    # Numeric: sacar 3
    for _ in range(3):
        rank, value = num.output()
        print(f"Numeric value {rank}: {value}")
    # Text: sacar 2
    for _ in range(2):
        rank, value = txt.output()
        print(f"Text value {rank}: {value}")
    # Log: sacar 1
    rank, value = log.output()
    print(f"Log entry {rank}: {value}")
    print()
    stream.print_processors_stats()


if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===", end="\n\n")
    main()
