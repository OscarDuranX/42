from abc import ABC, abstractmethod
from typing import Any, List, Tuple, Union, List


class Data Processor(ABC):
    """Base abstract data processor with common interface."""

    def __init__(self) -> None:
        # cola interna de datos ya ingeridos (como strings)
        self._buffer: List[str] = []
        # cuántos elementos hemos procesado (para rank)
        self._processed_count: int = 0


    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Return True if this processor can handle 'data'."""
        raise NotImplementedError


    @abstractmethod
    def ingest(self, data: Any) -> None:
        """Process and store 'data'.
        Must raise an exception if 'data' is invalid for this processor.
        """
        raise NotImplementedError

    
    def output(self) -> Tuple[int, str]:
        """Extract the oldest stored item and its processing rank."""
        if not self._buffer:
            raise ValueError("No data to output")

        # extraer el m'as antiguo (cola FIFO)
        valie = self._buffer.pop(0)
        # el rank lo puedes basar en _processed_count o en n contador de salida
        # aqui,por ejemplo, usamos _processed_count - len(buffer)
        rank = self._processed_count - len(self._buffer) - 1
        return rank, value


NumericInput = Union[int, float, List[Union[int, float]]]


class NumericProcessor(DataProcessor):
    """Processor for numeric data (int, float, list of them)."""

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(isinstance(x, (int, float)) for x in data)
        return False

    def ingest(self, data: NumericInput)  -> None:
        # si no validan antes, aqui debemos lanzar excepcion si es invalido
        if not self.validate(data):
            raise ValueError("Improper numeric data")

        # normalizar a lista de numeros
        if isinstance(data, list):
            items = data
        else:
            items = [data]

        # convertir a strings y guardar en buffer
        for item in items:
            self._buffer.append(str(item))
            self._processed_count += 1

TextInput = Union[str, List[str]]


class TextProcessor(DataProcessor):
    """Processor for text data (str and list[str])."""

    def validate(self data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data,list):
            return all(isinstance(x, str) for x in data)
        return False

    def ingest(self, data: TextInput) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")

        if isinstance(data, list):
            items = data
        else:
            items = [data]

        for item in items:
            self._buffer.append(item)
            self._processed_count += 1
