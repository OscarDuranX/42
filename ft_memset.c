#include <stdio.h>
#include <string.h>
void	ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char*)b;
	while (len-- > 0)
		*(tmp_ptr++) = (unsigned char)c;
	return (b);	
}

/*int main(void) {
    char buffer[10]; // Reserva espacio para 10 caracteres (incluyendo '\0' si es cadena)

    // 1. Rellenar con el carácter 'A' (ASCII 65) 5 veces
    ft_memset(buffer, 'A', 5); // Rellena los primeros 5 bytes
    buffer[5] = '\0'; // Añadir terminador nulo para que sea una cadena válida
    printf("Después de ft_memset(buffer, 'A', 5): %s\n", buffer); // Salida: AAAAA

    // 2. Rellenar con el valor 0 (para inicializar a nulos/vacío)
    char data[20];
    ft_memset(data, 0, sizeof(data)); // Rellena toda la memoria con bytes nulos
    printf("Después de ft_memset(data, 0, sizeof(data)): '%s' (longitud %zu)\n", data, strlen(data)); // Salida: '' (cadena vacía, longitud 0)

    // 3. ¡Cuidado con desbordamientos!
    char small_buffer[3];
    ft_memset(small_buffer, 'X', 10); // ¡ERROR! Intentar escribir fuera de la memoria reservada.

    return 0;
}*/
