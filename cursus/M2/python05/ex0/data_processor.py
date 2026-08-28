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


def main() -> None:
    print("=== Code Nexus - Data Processor ===", end="\n\n")

    num = NumericProcessor()
    txt = TextProcessor()
    log = LogProcessor()

    print("Testing NumericProcessir...")
    print(f"Trying to validate input '42': {num.validate(42)}")
    print(f"Trying to validate input 'Hello': {num.validate('Hello')}")

    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num.ingest("foo")  # debe lanzar ValueError
    except ValueError as e:
        print(f"Got exception: {e}")

    print("Processing data: [1, 2, 3, 4, 5]")
    num.ingest([1, 2, 3, 4, 5])
    print("Extraction 3 value...")
    for _ in range(3):
        rank, value = num.output()
        print(f"Numerci value {rank}: {value}")

    print()
    print("Testing TextProcessor...")
    print(f"Trying to validate input '42': {txt.validate(42)}")
    texts = ["Hello", "Nexus", "World"]
    print(f"Processing data: {texts}")
    txt.ingest(texts)
    print("Extracting 1 value...")
    rank, value = txt.output()
    print(f"Text value 0: {value}")

    print()
    print("Testing LogProcessor...")
    print(f"Trying to validate input 'Hello': {log.validate('Hello')}")
    logs = [
        {
            "log_level": "NOTICE",
            "log_message": "Connection to server"
        },
        {
            "log_level": "ERROR",
            "log_message": "Unauthorized access!!"
        }
    ]

    print(f"Processing data: {logs}")
    log.ingest(logs)
    print("Extracting 2 values...")
    for _ in range(2):
        rank, value = log.output()
        print(f"Log entry {rank}: {value}")


if __name__ == "__main__":
    main()
