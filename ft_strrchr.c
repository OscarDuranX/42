#include <stdio.h>

char	*ft_strrchr(char const *str, int c)
{
	const char *ini;

	ini = str;
	while(*str != '\0')
		str++;
	while(*str != *ini && c != *str)
		str--;
	if(c == *str)
		return ((char *) str);
	return (0);
}

/*int main() {
    const char *cadena = "hola mundo, hola C";
    char *puntero;
    int caracter_a_buscar = 'o';

    // Busca la última 'o'
    puntero = ft_strrchr(cadena, caracter_a_buscar);

    if (puntero != NULL) {
        printf("Última aparición de '%c' encontrada en: %s\n", caracter_a_buscar, puntero);
        // Salida: Última aparición de 'o' encontrada en: o mundo, hola C
    } else {
        printf("El caracter '%c' no fue encontrado.\n", caracter_a_buscar);
    }

    // Buscando un caracter que no existe
    puntero = ft_strrchr(cadena, 'z');
    if (puntero == NULL) {
        printf("El caracter 'z' no fue encontrado.\n");
    }

    return 0;
}*/
