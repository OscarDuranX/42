import importlib
from typing import Dict, Tuple, Any

PackageInfo = Tuple[bool, str | None]


def print_dependency_status(deps: Dict[str, Tuple[bool, str | None]]) -> None:
    print(
        "LOADING STATUS: Loading programs...\n\n"
        "Checking dependencies:"
    )

    for name, (ok, version) in deps.items():
        if not ok:
            print(
                f"[MISSING] {name} - Please install via:\n"
                "  pip:   pip install -r requirements.txt\n"
                "  poetry: poetry install && poetry run python loading.py"
            )
        else:
            print(f"[OK] {name} ({version}) - Ready")


def generate_matrix_data() -> Any:
    import numpy as np
    return np.random.randn(1000)


def analyze_data(data: Any) -> Any:
    import pandas as pd

    # Convertir el array de numpy en un DataFrame con una columna
    df = pd.DataFrame({"value": data})

    # Añadir algunas columnas de analisis
    df["abs_value"] = df["value"].abs()
    return df


def create_visualization(df: Any, output_path: str =
                         "matrix_analysis.png") -> None:
    import matplotlib.pyplot as plt

    # Crea figura
    plt.figure(figsize=(8, 4))

    # Histograma de la columna "value"
    plt.hist(df["value"], bins=100, alpha=1, edgecolor="green")
    plt.title("Matrix value distribution")
    plt.xlabel("Value")
    plt.ylabel("Frequency")

    # Guarda la imagen
    plt.tight_layout()
    plt.savefig(output_path)
    plt.close()


def check_dependencies() -> Dict[str, Tuple[bool, str | None]]:
    packages = ["numpy", "pandas", "matplotlib", "requests"]
    deps: Dict[str, PackageInfo] = {}

    for name in packages:
        try:
            module = importlib.import_module(name)
            version = getattr(module, "__version__", None)
            deps[name] = (True, version)
        except ImportError:
            deps[name] = (False, None)
    return deps


def main() -> None:
    deps = check_dependencies()
    print_dependency_status(deps)

    if (not deps["numpy"][0]
            or not deps["pandas"][0]
            or not deps["matplotlib"][0]):
        return

    data = generate_matrix_data()
    df = analyze_data(data)
    print(
        "\nAnalyzing Matrix data...\n"
        "Processing 1000 data points...\n"
        "Generating visualization...\n"
    )
    create_visualization(df)
    print(
        "Analysis complete!\n"
        "Results saved to: matrix_analysis.png"
    )


if __name__ == "__main__":
    main()
