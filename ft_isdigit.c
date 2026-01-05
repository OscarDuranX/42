#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*int main() {
    char caracter = '5';
    char otro_caracter = 'x';

    if (ft_isdigit(caracter)) {
        printf("'%c' es un digito.\n", caracter); // Se imprimirá esto
    } else {
        printf("'%c' no es un digito.\n", caracter);
    }

    if (ft_isdigit(otro_caracter)) {
        printf("'%c' es un digito.\n", otro_caracter);
    } else {
        printf("'%c' no es un digito.\n", otro_caracter); // Se imprimirá esto
    }

    return 0;
}*/
