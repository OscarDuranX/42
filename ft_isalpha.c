#include <stdio.h>

int	ft_isalpha(char c)
{
	if (c >= 'a' && c <='z')
		return (1024);
	else if (c >= 'A' && c <='Z')
		return (1024);
	else
		return (0);

}

/*int main() {
    char c1 = 'a';
    char c2 = 'B';
    char c3 = '5';
    char c4 = '$';

    // Comprobando c1
    if (ft_isalpha(c2)) {
        printf("'%c' es una letra.\n", c1); // Salida: 'a' es una letra.
    } else {
        printf("'%c' no es una letra.\n", c1);
    }

    // Comprobando c3
    if (ft_isalpha(c4)) {
        printf("'%c' es una letra.\n", c3);
    } else {
        printf("'%c' no es una letra.\n", c3); // Salida: '5' no es una letra.
    }

    return 0;
}*/
