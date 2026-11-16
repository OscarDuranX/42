from enum import Enum
from typing import Annotated


from pydantic import (
        BaseModel,
        Field,
        BeforeValidator,
        ConfigDict,
        PositiveInt,
        field_validator,
)


def _parse_int(value: object) -> object:
    """Convierte '12' o '-3' a int; rechaza '1.5' o 'abc'."""
    if isinstance(value, str):
        try:
            return int(value)
        except ValueError:
            raise ValueError(f"'{value}' is not an integer") from None
    return value


IntFromText = Annotated[int, BeforeValidator(_parse_int)]
PositiveIntFromText = Annotated[
    int, BeforeValidator(_parse_int), Field(gt=0)
]


class ZoneType(str, Enum):
    """Tipos de zona permitidos por el formato."""

    NORMAL = "normal"
    BLOCKED = "blocked"
    RESTRICTED = "restricted"
    PRIORITY = "priority"

    @property
    def movement_cost(self) -> int:
        """Turnos necesarios para enrar en una zona de este tipo."""
        costs = {
            ZoneType.NORMAL: 1,
            ZoneType.PRIORITY: 1,
            ZoneType.RESTRICTED: 2,
        }
        if self not in costs:
            raise ValueError("blocked zones cannot be entered")
        return costs[self]


class FleetConfig(BaseModel):
    """Linea 'nb_drones: N'."""

    model_config = ConfigDict(frozen=True)

    nb_drones: PositiveIntFromText


class Hub(BaseModel):
    """Zona validada del mapa.

    Nota: max_drones se ignota en start/end (ver MapData.zone_capacity).
    """

    model_config = ConfigDict(frozen=True)

    name: str
    x: IntFromText
    y: IntFromText
    zone_type: ZoneType = ZoneType.NORMAL
    color: str | None = None
    max_drones: PositiveIntFromText = 1

    @field_validator("name")
    @classmethod
    def _validate_name(cls, value: str) -> str:
        """Prohibe guiones y espacios en el nombre."""
        if not value or "-" in value or any(c.isspace() for c in value):
            raise ValueError(
                f"invalid hub name '{value}': dashes and spaces "
                "are not allowed"
            )
        return value

    @property
    def is_blocked(self) -> bool:
        """Indica si los drones tienen prohibido entrar."""
        return self.zone_type is ZoneType.BLOCKED

    @property
    def movement_cost(self) -> int:
        """Turnos que cuesta entrar e esta zona."""
        return self.zone_type.movement_cost


class Connection(BaseModel):
    """Enlace bidireccional entre dos hubs."""

    model_config = ConfigDict(frozen=True)

    source: str
    target: str
    max_link_capacity: PositiveIntFromText = 1

    @property
    def key(self) -> tuple[str, str]:
        """Devuelve una clave independiente de la direccion."""
        first, second = sorted((self.source, self.target))
        return (first, second)

    def other_end(self, hub_name: str) -> str:
        """Devuelve el extremo opuesto a hub_name."""
        if hub_name == self.source:
            return self.target
        if hub_name == self.target:
            return self.source
        raise ValueError(f"'{hub_name}' is not part of {self.key}")


class MapData(BaseModel):
    """Mapa completo tras validar el archivo de entrada"""

    model_config = ConfigDict(frozen=True)

    drone_count: PositiveInt
    hubs: dict[str, Hub]
    start_hub: str
    end_hub: str
    connections: list[Connection] = Field(default_factory=list)

    def zone_capacity(self, hub_name: str) -> int | None:
        """Capacidad real de una zona; None significa sin limite.

        El subject dice que start y end no tienen limite.
        """
        if hub_name in (self.start_hub, self.end_hub):
            return None
        return self.hubs[hub_name].max_drones
