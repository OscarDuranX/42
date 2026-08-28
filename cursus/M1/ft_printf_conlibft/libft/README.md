*Este proyecto ha sido creado como parte del currículo de 42 por <oduran-m>.*

# LIBFT.H

## Descripción

Libft es un proyecto individual en 42 que nos hace a recrear algunas funciones de la biblioteca C estándar para futuros proyectos y tener una comprensión más profunda de las estructuras de datos y los algoritmos básicos. Este proyecto permite entender la forma en la que estas funciones operan, cómo implementarlas y aprender a utilizarlas. En 42 no se nos permite usar algunas bibliotecas estándar en nuestros proyectos, por lo que tenemos que crear una librería propia, que será muy útil ya que la utilizaremos en los siguientes proyectos de C.

A lo largo del desarrollo se han puesto en práctica buenas prácticas de programación, gestión de errores y diseño modular, siguiendo las normas y estándares de 42.

## Instrucciones

### Requisitos previos

- Sistema operativo: <Linux / macOS>
- Compilador: <gcc / clang>
- Otras dependencias: <si aplica>

### Compilación

Desde la raíz del repositorio, ejecutar:

```bash
make

Esto generará el ejecutable libft.o.

Para limpiar los archivos objeto:

make clean


Para limpiar completamente el proyecto:

make fclean

Ejecución

Una vez compilado, ejecutar:

cc -Wall -Werror -Wextra <nombre programa en c> libft.a


Ejemplo:

./<nombre_del_ejecutable> <ejemplo_de_argumentos>

Librería del proyecto

Este proyecto incluye una librería propia llamada "libft.h".

Descripción general

La librería "libft.h" ha sido desarrollada específicamente para este proyecto con el objetivo de tener una libreria con todas las funciones que necesitaremos al futuro para poder programar cualquier tipo de funcion.
Contiene funciones reutilizables que permiten realizar funciones muy repetitivas lo mas rapido possible.

Contenido de la librería

La librería incluye, entre otras, las siguientes funcionalidades:

Gestión de <memoria / strings / listas / estructuras>

Funciones utilitarias para <parsing / validación / cálculo>


Uso de la librería

Para utilizar la librería dentro del proyecto:

#include "libft.h"


La librería se compila automáticamente junto con el resto del proyecto mediante el Makefile.

Recursos
Referencias técnicas

Documentación oficial del lenguaje C:
https://en.cppreference.com/w/c

Manual de Linux (man):
man <función>

Norminette de 42

Documentación específica del proyecto:
<enlace si aplica>

Uso de Inteligencia Artificial

Se ha utilizado Inteligencia Artificial como apoyo en tareas específicas, tales como:

Comprensión y explicación de conceptos teóricos

Revisión de errores de compilación

Propuestas de mejora en la estructura del código

Ayuda en la redacción de documentación

En ningún caso la IA ha sido utilizada para generar directamente el código final entregado, respetando las normas académicas de 42.

Estructura del proyecto
.
├── src/
│   └── <archivos_fuente>
├── include/
│   └── <headers>
├── lib/
│   └── <libreria>
├── Makefile
└── README.md

Autor(es)
<oduran-m>
