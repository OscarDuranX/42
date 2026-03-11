Este proyecto ha sido creado como parte del currículo de 42 por oduran-m.

Descripción
get_next_line es una función en C que permite leer de un descriptor de archivo línea a línea, de forma segura y eficiente.
El objetivo del proyecto es implementar esta función respetando las restricciones de 42 (uso de read, malloc, free, sin variables globales ni lseek) y manejando correctamente casos como archivos vacíos, líneas muy largas, ausencia de \n final y lectura desde stdin.
Además, el proyecto sirve para practicar el uso de variables estáticas, manejo de memoria dinámica y diseño de funciones auxiliares para manipulación de cadenas.

Instrucciones
Estructura del proyecto
Archivos principales:

get_next_line.c: implementación de get_next_line y funciones auxiliares internas (get_read_line, get_good_line, get_bad_line).

get_next_line_utils.c: funciones de utilidad (ft_strlen, ft_strchr, ft_strjoin, ft_memcpy).

get_next_line.h: prototipos y definición de BUFFER_SIZE.

(Opcional) main.c: archivo de pruebas local, no entregable.

Compilación
El proyecto debe compilarse con cc y las flags:

-Wall -Wextra -Werror

-D BUFFER_SIZE=<n> para indicar el tamaño del búfer usado por read.

Ejemplo de compilación para pruebas:

bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c main.c
Si no se pasa -D BUFFER_SIZE, el valor por defecto debe estar definido en get_next_line.h.

Ejecución
Ejemplo de uso en un main.c:

c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int   fd;
	char *line;

	fd = open("archivo.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
También se puede usar con stdin pasando 0 como descriptor de archivo.

Recursos
Referencias técnicas
Manual de read(2) en Linux.

Documentación de funciones estándar de C: malloc, free, printf.

Guías de proyectos de 42 sobre get_next_line y libft.

GitBook 42 Libft/ft_strchr, ft_strlen, ft_strjoin, ft_memcpy para la referencia de comportamiento de estas funciones.

Uso de IA en este proyecto
Se ha utilizado IA como apoyo puntual en:

Comprender mensajes de error de valgrind y malloc(): corrupted top size.

Razonar sobre fugas de memoria y orden correcto de free en la gestión de stash.

Refinar el diseño de funciones auxiliares (get_good_line, get_bad_line, get_read_line) y su interacción.

Redacción de este README siguiendo los requisitos del enunciado.

No se ha copiado ningún código completo generado por IA de forma directa en la entrega final; las decisiones de diseño, la escritura y depuración del código se han realizado manualmente, contrastando siempre con la norma de 42, los testers (paco, francinette) y pruebas propias.

Algoritmo y decisiones técnicas
Idea general
El objetivo es devolver una línea completa por cada llamada a:

c
char *get_next_line(int fd);
donde:

“Línea” incluye el carácter \n si existe.

Si no hay nada más que leer o hay error, se devuelve NULL.

Para conseguirlo, se utiliza un búfer estático por descriptor (limitado a una única variable estática stash en la parte obligatoria) que acumula los datos leídos que todavía no se han devuelto.

Flujo del algoritmo
Acumulación de datos (get_read_line)

Mientras en stash no haya un \n y read siga devolviendo bytes (amount > 0), se lee del descriptor con read(fd, buffer, BUFFER_SIZE).

Cada lectura se termina con buffer[amount] = '\0'.

Se concatena el contenido de buffer al final de stash con ft_strjoin, liberando la versión anterior de stash para evitar fugas.

Si read devuelve < 0 o falla algún malloc, se devuelve NULL para indicar error.

Extracción de la línea (get_good_line)

A partir de stash, se busca el primer \n o el final de cadena.

Se calcula la longitud de la línea a devolver: hasta \n incluido si existe; hasta '\0' si no.

Se reserva memoria justa (len + 1), se copia el fragmento y se añade '\0'.

Si stash es NULL o vacío, se devuelve NULL.

Actualización del resto (get_bad_line)

Una vez extraída la línea, se calcula la posición a partir de la cual empieza el “resto” (start = ft_strlen(line)).

Si start es mayor o igual que la longitud de stash, no hay resto y se devuelve NULL.

En caso contrario, se reserva memoria para el resto, se copia desde stash[start] hasta el final y se termina en '\0'.

Coordinación en get_next_line

stash es una variable estática que conserva su valor entre llamadas.

En cada llamada:

Se actualiza stash con get_read_line(fd, stash).

Si stash es NULL, se devuelve NULL (error de lectura o no hay datos).

Se obtiene line = get_good_line(stash).

Si line es NULL, se libera stash, se pone a NULL y se devuelve NULL (EOF sin más datos).

Si hay línea, se calcula stash = get_bad_line(stash, ft_strlen(line)), se libera la versión anterior de stash y se devuelve line.

Justificación del enfoque
Eficiencia en lecturas:
Solo se llama a read mientras no haya un salto de línea en lo que ya está acumulado. Esto evita leer todo el archivo de golpe y respeta el enunciado de “leer lo menos posible por llamada”.

Uso de variable estática:
stash permite mantener entre llamadas los datos que han sido leídos pero todavía no devueltos. Es la herramienta clave para que get_next_line sea “reentrante” a nivel lógico y pueda leer línea a línea sin perder información.

Separación de responsabilidades:

get_read_line se ocupa solo de leer y rellenar stash.

get_good_line se centra en extraer la línea actual.

get_bad_line gestiona el resto para la próxima llamada.
Esto hace el código más fácil de entender, probar y depurar.

Gestión explícita de memoria:
Cada vez que se crea una nueva versión de stash (tras un ft_strjoin o un get_bad_line), se libera la versión antigua para evitar fugas.
Cualquier cadena devuelta (line) es responsabilidad del llamador (free(line) después de usarla).

Este diseño cumple con las restricciones del proyecto, maneja correctamente la mayoría de casos límite habituales en get_next_line y se ajusta a los objetivos pedagógicos: uso de variables estáticas, manejo cuidadoso de memoria dinámica y diseño de un flujo robusto alrededor de read().
