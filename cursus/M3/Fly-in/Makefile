SHELL		:= /bin/bash
VENV		:= venv
ACTIVATE	:= source $(VENV)/bin/activate
MAP		?= maps/easy/01_linear_path.txt


# Crea entorno virtual si no existe, si existe, no hace nada.
$(VENV)/bin/activate:
	python3 -m venv $(VENV)


# Instala pydantic si todavia no esta instalado.
install: $(VENV)/bin/activate
	$(ACTIVATE) && \
	if python -c "import pydantic" 2>/dev/null; then \
		echo "pydantic is already installed"; \
	else \
		pip install pydantic; \
	fi
 
# Herramientas de desarrollo
install-dev: install
	$(ACTIVATE) && \
	if python -c "import flake8, mypy, pytest" 2>/dev/null; then \
		echo "dev tools are already installed"; \
	else \
		pip install flake8 mypy pytest; \
	fi

run: install
	$(ACTIVATE) && python main.py $(MAP)

debug: install
	$(ACTIVATE) && python -m pdb main.py $(MAP)

test: install-dev
	$(ACTIVATE) && python -m pytest -q

lint: install-dev
	$(ACTIVATE) && flake8 . --exclude $(VENV) && \
	mypy . --exclude $(VENV) --warn-return-any --warn-unused-ignores \
		--ignore-missing-imports --disallow-untyped-defs \
		--check-untyped-defs

lint-strict: install-dev
	$(ACTIVATE) && flake8 . --exclude $(VENV) && \
	mypy . --exclude $(VENV) --strict

clean:
	find . -type d -name "__pycache__" -not -path "./$(VENV)/*" \
		-prune -exec rm -rf {} + 
	rm -rf .mypy_cache .pytest_cache

fclean: clean
	rm -rf $(VENV)

.PHONY: install install-dev run debug test lint lint-strict clean fclean
