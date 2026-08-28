from enum import Enum
from typing import List

from pydantic import BaseModel, model_validator  # type: ignore
from pydantic import Field, ValidationError


class Rank(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):  # type: ignore
    member_id: str = Field(
        ...,
        min_length=3,
        max_length=10,
        description="Unique crew member identifier",
    )
    name: str = Field(
        ...,
        min_length=2,
        max_length=50,
        description="Crew member full name",
    )
    rank: Rank = Field(
        ...,
        description="Crew member rank"
    )
    age: int = Field(
        ...,
        ge=18,
        le=80,
        description="Crew member age in years",
    )
    specialization: str = Field(
        ...,
        min_length=3,
        max_length=30,
        description="Crew member specialization",
    )
    years_experience: int = Field(
        ...,
        ge=0,
        le=50,
        description="Years of experience",
    )
    is_active: bool = Field(
        default=True,
        description="Whether the crew member is active",
    )


class SpaceMission(BaseModel):  # type: ignore
    mission_id: str = Field(
        ...,
        min_length=5,
        max_length=15,
        description="Unique mission identifier",
    )
    mission_name: str = Field(
        ...,
        min_length=3,
        max_length=100,
        description="Mission name",
    )
    destination: str = Field(
        ...,
        min_length=3,
        max_length=50,
        description="Mission destination",
    )
    launch_date: str = Field(
        ...,
        description="Launch date and time",
    )
    duration_days: int = Field(
        ...,
        ge=1,
        le=3650,
        description="Mission duration in days",
    )
    crew: List[CrewMember] = Field(
        ...,
        min_length=1,
        max_length=12,
        description="Mission crew members",
    )
    mission_status: str = Field(
        default="planned",
        description="Mission status",
    )
    budget_millions: float = Field(
        ...,
        ge=1.0,
        le=10000.0,
        description="Mission budget in millions of dollars",
    )

    @model_validator(mode="after")  # type: ignore
    def check_safety_rules(self) -> "SpaceMission":
        # 1. Mission ID must start with "M"
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        # 2. Must have at least one Commander or Captain
        has_leader = any(
            member.rank in (Rank.commander, Rank.captain)
            for member in self.crew
        )
        if not has_leader:
            raise ValueError(
                "Mission must have at least one Commander or Captain"
            )

        # 3. Long missions (>365 days) need 50% experienced crew (5+ years)
        if self.duration_days > 365:
            experienced_count = sum(
                1 for member in self.crew if member.years_experience >= 5
            )
            if experienced_count < len(self.crew) / 2:
                raise ValueError(
                    "Long missions (>365 days) need at least"
                    "50% experienced crew (5+ years)"
                )

        # 4. All crew members must be active
        inactive_members = [m.name for m in self.crew if not m.is_active]
        if inactive_members:
            raise ValueError(
                "All crew members must be active. Inactive:"
                f" {', '.join(inactive_members)}"
            )

        return self


def create_valid_mission() -> SpaceMission:
    crew = [
        CrewMember(
            member_id="C001",
            name="Sarah Connor",
            rank=Rank.commander,
            age=38,
            specialization="Mission Command",
            years_experience=10,
        ),
        CrewMember(
            member_id="C002",
            name="John Smith",
            rank=Rank.lieutenant,
            age=32,
            specialization="Navigation",
            years_experience=7,
        ),
        CrewMember(
            member_id="C003",
            name="Alice Johnson",
            rank=Rank.officer,
            age=29,
            specialization="Engineering",
            years_experience=6,
        ),
    ]

    mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date="2024-03-01T08:00:00",
        duration_days=900,
        crew=crew,
        mission_status="planned",
        budget_millions=2500.0,
    )
    return mission


def try_create_invalid_mission() -> None:
    crew = [
        CrewMember(
            member_id="C004",
            name="Bob Rookie",
            rank=Rank.cadet,
            age=22,
            specialization="Intern",
            years_experience=1,
        )
    ]

    try:
        SpaceMission(
            mission_id="M2024_Test",     # no empeiza por M
            mission_name="Test Mission",
            destination="Moon",
            launch_date="2024-05-01T10:00:00",
            duration_days=100,
            crew=crew,
            budget_millions=10.0,
        )
    except ValidationError as exc:
        print(
            "========================================\n"
            "Expected validation error:\n"
            f"{exc}"
        )


def main() -> None:
    mission = create_valid_mission()

    print(
        "Space Mission Crew Validation\n"
        "========================================\n"
        "Valid mission created:\n"
        f"Mission: {mission.mission_name}\n"
        f"ID: {mission.mission_id}\n"
        f"Destination: {mission.destination}\n"
        f"Duration: {mission.duration_days} days\n"
        f"Budget: ${mission.budget_millions}M\n"
        "Crew members:\n"
    )
    for member in mission.crew:
        print(
            f"- {member.name}"
            f" ({member.rank.value}) -"
            f" {member.specialization}"
        )
    try_create_invalid_mission()


if __name__ == "__main__":
    main()
