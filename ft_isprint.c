#include <stdio.h>
#include <ctype.h> // Necesario para isprint

int	ft_isprint(char c)
{
	printf("valor %d\n", c);
	if (c >= 0 && c <= 32 || c == 127)	
		return (0);
	else
		return (16384);
}

/*int main() {
    char c1 = 'A';
    char c2 = '\\'; // Espacio
    char c3 = '\t'; // Tabulación (no imprimible)

    printf("isprint('%c'): %d\n", c1, ft_isprint(c1)); // Devuelve no-cero (verdadero)
    printf("isprint('%c'): %d\n", c2, ft_isprint(c2)); // Devuelve no-cero (verdadero)
    printf("isprint('DEL'): %d\n", isprint(92));    // Devuelve cero (falso)

    return 0;
}*/
