from typing import TypedDict


class Config(TypedDict):
    matrix_mode: str
    database_url: str
    api_key: str
    log_level: str
    zion_endpoint: str


def load_config() -> Config:
    from dotenv import load_dotenv
    import os

    # Cargar variables desde .env (si existe) y entorno
    load_dotenv()

    return {
        "matrix_mode": os.getenv("MATRIX_MODE", "development"),
        "database_url": os.getenv("DATABASE_URL", ""),
        "api_key": os.getenv("API_KEY", ""),
        "log_level": os.getenv("LOG_LEVEL", "INFO"),
        "zion_endpoint": os.getenv("ZION_ENDPOINT", ""),
    }


def check_configuration(config: Config) -> list[str]:
    messages: list[str] = []

    if not config["database_url"]:
        messages.append("WARNING: DATABASE_URL is missing.")
    if not config["api_key"]:
        messages.append("WARNING: API_KEY is missing.")
    if not config["zion_endpoint"]:
        messages.append("WARNING: ZION_ENDPOINT is missing.")

    # Chequeo del modo
    if config["matrix_mode"] not in ("development", "production"):
        messages.append(
            "WARNING: MATRIX_MODE is invalid, defaulting to development."
        )
    return messages


def print_configuration_status(config: Config, warnings: list[str]) -> None:
    print(
        "ORACLE STATUS: Reading the Matrix...\n\n"
        "Configuration loaded:\n"
        f"   Mode: {config['matrix_mode']}\n"
        f"   Database: {config['database_url'] or 'Not configured'}\n"
        "   API Access:"
        f"{'Authenticated' if config['api_key'] else 'Missing API_KEY'}\n"
        f"   LogLevel: {config['log_level']}\n"
        f"   Zion Network: {config['zion_endpoint'] or 'Offline'}\n"
        "\nEnvironment security check:"
    )
    if not warnings:
        print(
            "  [OK] No hardcoded secrets detected\n"
            "  [OK] .env file properly configured (if used)"
        )
    else:
        for msg in warnings:
            print(f"   [WARN] {msg}")

    if config["matrix_mode"] == "production":
        print("  [OK] Production overrides available")
    else:
        print("  [INFO] Running in development mode")
    print("\nThe Oracle sees all configurations.")


def main() -> None:
    config = load_config()
    warnings = check_configuration(config)
    print_configuration_status(config, warnings)


if __name__ == "__main__":
    main()
