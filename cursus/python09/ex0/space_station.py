from typing import Optional

from pydantic import BaseModel, Field, ValidationError  # type: ignore


class SpaceStation(BaseModel):  # type: ignore
    station_id: str = Field(
        ...,
        min_length=3,
        max_length=10,
        description="Unique station identifier",
    )
    name: str = Field(
        ...,
        min_length=1,
        max_length=50,
        description="Human-readable station name",
    )
    crew_size: int = Field(
        ...,
        ge=1,
        le=20.0,
        description="Number of crew members on station",
    )
    power_level: float = Field(
        ...,
        ge=0.0,
        le=100.0,
        description="Power level percentage",
    )
    oxygen_level: float = Field(
        ...,
        ge=0.0,
        le=100.0,
        description="Oxygen level percentage",
    )
    last_maintenance: str = Field(
        ...,
        description="Whether the station is currently operational",
    )
    is_operational: bool = Field(
        default=True,
        description="Whether the station is currently operational",
    )
    notes: Optional[str] = Field(
        default=None,
        max_length=200,
        description="Optional notes about the station",
    )


def create_valid_station() -> SpaceStation:
    """Crea y devuelve una estacion valida de ejemplo."""
    station = SpaceStation(
        station_id="ISS001",
        name="International Delta Space Station",
        crew_size=6,
        power_level=85.5,
        oxygen_level=92.3,
        last_maintenance="2024-01-01T12:00:00",
        # is_operational usa el default True
        notes="Orbiting Earth in low Earth orbit",
    )
    return station


def try_create_invalid_station() -> None:
    """Crea/intenta una estacion invalida y muesta el error de validacion."""
    try:
        # crew_size fuera de rango (debe ser <= 20)
        SpaceStation(
            station_id="BAD001",
            name="Overcrowded Station",
            crew_size=100,      # invalid
            power_level=50.0,
            oxygen_level=80.0,
            last_maintenance="2024-01-01T12:00:00",
            is_operational=True,
        )
    except ValidationError as exc:
        print(
            "========================================\n"
            "Expected validation error:\n"
            f"{exc}"
        )


def main() -> None:
    # Crear y mostrar una estacion valida
    station = create_valid_station()

    print(
        "Space Station Data Validation\n"
        "========================================\n"
        "Valid station created:\n"
        f"ID: {station.station_id}\n"
        f"Name: {station.name}\n"
        f"Crew: {station.crew_size}\n"
        f"Power: {station.power_level}%\n"
        f"Oxygen: {station.oxygen_level}%\n"
        f"Status: {'Operational' if station.is_operational else 'Offline'}\n"
    )
    # Intentar crear una estacion invalida
    try_create_invalid_station()


if __name__ == "__main__":
    main()
