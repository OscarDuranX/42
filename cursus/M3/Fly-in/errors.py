"""Excepciones propias del proyecto."""


class ParseError(Exception):
    """Error de sintazis o d reglas del archivo de mapa.
    
    Args:
        message: Descripcion de la causa del error.
        line_number: Linea del archivo donde ocurre (None si no aplica).
    """

    def __init__(self, message: str, line_number: int | None = None) -> None:
        self.message = message
        self.line_number = line_number
        super().__init__(str(self))

    def __str__(self) -> str:
        """Devuelve el mensaje con la linea, si se conoce."""
        if self.line_number is None:
            return self.message
        return f"Line {self.line_number}: {self.message}"

