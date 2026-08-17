from enum import Enum
from typing import Optional

from pydantic import BaseModel, model_validator  # type: ignore
from pydantic import Field, ValidationError


class ContactType(str, Enum):
    radio = "radio"
    visual = "visual"
    physical = "physical"
    telepathic = "telepathic"


class AlienContact(BaseModel):  # type: ignore
    contact_id: str = Field(
        ...,
        min_length=5,
        max_length=15,
        description="Unique contact identifier",
    )
    timestamp: str = Field(
        ...,
        description="Time of contact",
    )
    location: str = Field(
        ...,
        min_length=3,
        max_length=100,
        description="Location description",
    )
    contact_type: ContactType = Field(
        ...,
        description="Type of alien contact",
    )
    signal_strength: float = Field(
        ...,
        ge=0.0,
        le=10.0,
        description="Signal strength on 0-10 scale",
    )
    duration_minutes: int = Field(
        ...,
        ge=1,
        le=1440,
        description="Contact duration in minutes",
    )
    witness_count: int = Field(
        ...,
        ge=1,
        le=100,
        description="Number of human witnesses",
    )
    message_received: Optional[str] = Field(
        default=None,
        max_length=500,
        description="Optional message content",
    )
    is_verified: bool = Field(
        default=False,
        description="Whether the contact has been verified"
    )

    @model_validator(mode="after")  # type: ignore
    def check_business_rules(self) -> "AlienContact":
        # 1. Contact ID debe emepzar por "AC"
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")

        # 2. Physical contact reports must be verified
        if self.contact_type == ContactType.physical and not self.is_verified:
            raise ValueError("Physical contact reports must  be verified")

        # 3. Telepathic contact requires at least 3 witnesses
        if (self.contact_type == ContactType.telepathic
                and self.witness_count < 3):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
            )

        # 4. Strong signal (>7.0) should include received messages
        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError(
                "Strong signals (>7.0) should include a received message"
            )
        return self


def create_valid_contact() -> AlienContact:
    contact = AlienContact(
        contact_id="AC_2024_001",
        timestamp="2024-05-10T14:30:00",
        location="Area 51, Nevada",
        contact_type=ContactType.radio,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli",
        # is_verified usa el default False
    )
    return contact


def try_create_invalid_contact() -> None:
    try:
        AlienContact(
            contact_id="AC_2024_002",
            timestamp="2024-05-10T15:00:00",
            location="Deep Space Station",
            contact_type=ContactType.telepathic,
            signal_strength=5.0,
            duration_minutes=30,
            witness_count=1,  # menos de 3
            message_received=None,
            is_verified=False,
        )
    except ValidationError as exc:
        print(
            "======================================\n"
            "Expected validation error:\n"
            f"{exc}"
        )


def main() -> None:
    valid_contact = create_valid_contact()

    print("Alien Contact Log Validation")
    print("======================================")
    print("Valid contact report:")
    print(f"ID: {valid_contact.contact_id}")
    print(f"Type: {valid_contact.contact_type}")
    print(f"Location: {valid_contact.location}")
    print(f"Signal: {valid_contact.signal_strength}/10")
    print(f"Duration: {valid_contact.duration_minutes} minutes")
    print(f"Witnesses: {valid_contact.witness_count}")
    if valid_contact.message_received:
        print(f"Message: '{valid_contact.message_received}'\n")

    try_create_invalid_contact()


if __name__ == "__main__":
    main()
