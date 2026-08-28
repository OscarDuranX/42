from abc import ABC, abstractmethod


class HealCapability(ABC):
    """Abstract capability to heal."""

    @abstractmethod
    def heal(self, target: str | None = None) -> str:
        raise NotImplementedError


class TransformCapability(ABC):

    def __init__(self) -> None:
        self._transformed: bool = False

    @abstractmethod
    def transform(self) -> str:
        raise NotImplementedError

    @abstractmethod
    def revert(self) -> str:
        raise NotImplementedError
