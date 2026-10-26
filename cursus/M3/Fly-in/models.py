from enum import Enum
from pydantic import BaseModel, Field


class ZoneType(str, Enum):
    """Tipos de zona permitidos por el formato."""

    NORMAL = "normal"
    BLOCKED = "blocked"
    RESTRICTED = "restricted"
    PRIORITY = "priority"


class Hub(BaseModel):
    """Zona validada del mapa."""

    name: str
    x: int
    y: int
    zone_type: ZoneType = ZoneType.NORMAL
    color: str | None = None
    max_drones: int = Field(default=1, gt=0)


class Connection(BaseModel):
    """Enlace bidireccional entre dos hubs."""

    source: str
    target: str
    max_link_capacity: int = Field(default=1, gt=0)

    @property
    def key(self) -> tuple[str, str]:
        """Devuelve una clave independiente de la direccion."""
        return tuple(sorted((self.source, self.target)))


class MapData(BaseModel):
    """Mapa completo tras validar el archivo de entrada"""

    drone_count: int
    hubs: dict[str, Hub]
    connections: list[Connection]
    start_hub: str
    end_hub: str
