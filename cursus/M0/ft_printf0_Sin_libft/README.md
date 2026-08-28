Este proyecto ha sido creado como parte del currículo de 42 por oduran-m.
ft_printf
📌 Descripción
ft_printf es una recreación parcial de la función estándar printf de C.
El objetivo del proyecto es comprender en profundidad cómo funciona la impresión formateada, el manejo de argumentos variables y la conversión de distintos tipos de datos a cadenas imprimibles.

Esta implementación soporta los siguientes especificadores:

%c — Imprime un carácter.

%s — Imprime una cadena de caracteres.

%p — Imprime un puntero en formato hexadecimal con prefijo 0x.

%d — Imprime un número decimal con signo.

%i — Igual que %d.

%u — Imprime un número decimal sin signo.

%x — Imprime un número hexadecimal en minúsculas.

%X — Imprime un número hexadecimal en mayúsculas.

%% — Imprime el símbolo %.

El proyecto también incluye una integración con libft, reutilizando funciones como ft_putchar_fd y ft_putstr_fd.

🛠 Instrucciones
✔ Compilación
Ejecuta:

Código
make
Esto generará la librería:

Código
libftprintf.a
✔ Uso
En tu código C:

c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola %s, el número es %d\n", "mundo", 42);
    return 0;
}
Compila enlazando la librería:

Código
gcc main.c libftprintf.a -o programa
🧠 Elección del algoritmo y estructura de datos
La implementación de ft_printf se basa en un enfoque sencillo y eficiente:

🔹 Manejo de argumentos variables
Se utiliza va_list, va_start, va_arg y va_end para extraer los argumentos según el tipo especificado.
Cada conversión se gestiona en una función específica (print_char, print_string, print_int, etc.).

🔹 Conversión numérica (%d, %i)
Se usa división sucesiva entre 10 para extraer los dígitos.

Los dígitos se almacenan en un buffer temporal y se imprimen en orden inverso.

Se usa long para evitar problemas con INT_MIN.

🔹 Números sin signo (%u)
Misma técnica que %d, pero usando unsigned int.

No se maneja signo.

🔹 Hexadecimal (%x, %X)
Conversión mediante módulo 16.

Se usa una tabla de caracteres ("0123456789abcdef" o "0123456789ABCDEF").

Los dígitos se almacenan en un buffer y se imprimen en orden inverso.

🔹 Punteros (%p)
Se convierte el valor a hexadecimal manualmente.

Se añade el prefijo 0x.

Caso especial: puntero NULL imprime 0x0.

🔹 Cadenas (%s)
Se utiliza ft_putstr_fd de libft para imprimir la cadena completa.

Si el puntero es NULL, se imprime (null).

🔹 Caracteres (%c)
Se usa ft_putchar_fd para imprimir directamente el carácter.

🔹 Estructura de datos
No se usan estructuras complejas.
El proyecto se basa en:

Buffers locales en la pila.

Tablas de caracteres para conversiones.

Funciones auxiliares pequeñas y específicas.

Este enfoque minimiza el uso de memoria dinámica y simplifica la lógica.

📚 Recursos
Documentación y referencias
Manual de printf(3)

ISO C Standard — Sección sobre argumentos variádicos

Tutoriales sobre va_list y funciones variádicas

Documentación de 42 sobre libft

Uso de IA en el proyecto
Se utilizó IA como apoyo para:

Resolver dudas sobre comportamiento específico de %p.

Depurar errores relacionados con va_arg.

Mejorar la claridad del código y evitar comportamiento indefinido.

Redactar este README siguiendo los requisitos del enunciado.

La implementación final del código, la lógica de conversión y las decisiones técnicas fueron realizadas manualmente.

🧪 Ejemplo de uso
c
ft_printf("Char: %c\n", 'A');
ft_printf("String: %s\n", "Hola");
ft_printf("Pointer: %p\n", ptr);
ft_printf("Decimal: %d\n", -42);
ft_printf("Unsigned: %u\n", 42);
ft_printf("Hex lower: %x\n", 48879);
ft_printf("Hex upper: %X\n", 48879);
ft_printf("Percent: %%\n");
🗂 Estructura del proyecto
Código
ft_printf/
│
├── ft_printf.c
├── print_char.c
├── print_string.c
├── print_int.c
├── print_unsigned.c
├── print_hex.c
├── print_pointer.c
├── libft/ (submódulo con libft)
├── libftprintf.h
└── Makefile
