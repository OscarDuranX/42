#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t	sizesrc;
    size_t	i;
    if (!dest || !src)
        return (0);
    i = 0;
    sizesrc = ft_strlen(src);
    if (size != 0)
    {
        while (i < (size - 1) && src[i])
        {
            dest[i] = src[i];
            ++i;            
        }
        dest[i] = '\0';
    }
    return (sizesrc);
}
/*
int	main(void) 
{
    char	destino[10];
    const char	*origen = "Hola Mundo";
    size_t	len;

    // Copia "Hola Mundo" a destino, pero no más de 9 caracteres (más \0)
    len = ft_strlcpy(destino, origen, sizeof(destino));

    printf("Destino: %s\n", destino); // Imprime: Hola Mundo
    printf("Longitud de origen (intentada): %zu\n", len); // Imprime: 10
    printf("¿Fue truncada?: %s\n", len >= sizeof(destino) ? "Sí" : "No"); // Imprime: Sí

    return (0);
}*/
