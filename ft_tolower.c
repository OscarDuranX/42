#include <stdio.h>
#include <ctype.h> // Para usar tolower()

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int main() {
    char letra_mayus = 'A';
    char letra_minus = 'b';
    char numero = '5';

    printf("'%c' en minúscula es '%c'\n", letra_mayus, ft_tolower(letra_mayus));
    printf("'%c' en minúscula es '%c'\n", letra_minus, ft_tolower(letra_minus));
    printf("'%c' en minúscula es '%c'\n", numero, ft_tolower(numero));

    return 0;
}
