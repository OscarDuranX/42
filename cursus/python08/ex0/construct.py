import sys
import os
import site


def is_in_virtualenv() -> bool:
    if sys.prefix != sys.base_prefix:
        return True
    else:
        return False


def get_environment_info() -> dict[str, str | None]:
    current_python = sys.executable
    environment_path = sys.prefix
    virtualenv_name = os.path.basename(sys.prefix)

    try:
        package_paths = site.getsitepackages()
    except AttributeError:
        package_paths = []

    package_path = package_paths[0] if package_paths else None

    return {
        "current_python": current_python,
        "environment_path": environment_path,
        "virtualenv_name": virtualenv_name,
        "package_path": package_path,
    }


def print_inside_constructor(info: dict[str, str]) -> None:
    print(
        "MATRIX STATUS: Welcome to the construct\n\n"
        f"Current Pythone: {info['current_python']}\n"
        f"Virtual Environment: {info['virtualenv_name']}\n"
        f"Environment Path: {info['environment_path']}\n\n"
        "SUCCESS: You're in an islated environment!\n"
        "Safe to install packages without affecting\n"
        "the global system.\n\n"
        f"Package installation path:\n{info['package_path']}"
    )


def print_virtualenv_instructions() -> None:
    print(
        "No virtual environment detected.\n\n"
        "A virtual environment lets you isolate this project's packages\n"
        "from the global Python installation, keeping dependencies clean.\n\n"
        "To create a virtual environment (Unix/macOS):\n"
        "  python3 -m venv venv\n"
        "  source venv/bin/activate\n\n"
        "To create a virtual environment (Windows)\n"
        "  python3 -m venv venv\n"
        "  venv\\Scripts\\activate\n\n"
        "Once activated, run this script again to see the construct info."
    )


def print_global_environment(info: dict[str, str | None]) -> None:
    print(
        "Should detect no vritual enviroment and provide instructions:\n"
        "MATRIX STATUS: Your're still plugged in\n\n"
        f"CurrentPython: {info['current_python']}\n"
        "VirtualEnvironment: None detected\n\n"
        "WARNING: You're in the global environment!\n"
    )
    print_virtualenv_instructions()


def main():
    info = get_environment_info()
    if is_in_virtualenv():
        print_inside_constructor(info)
    else:
        print_global_environment(info)


if __name__ == "__main__":
    main()
