/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:42:21 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 18:43:08 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strchr(char const *str, int c)
{
	while (*str != '\0' && *str != c)
		str++;
	if (*str == c)
		return ((char *)str);
	return (0);
}

/*int main() {
    char *cadena = "hola mundo";
    char *resultado;
    char caracter_a_buscar = 'o';

    resultado = ft_strchr(cadena, caracter_a_buscar); // Busca 'o'

    if (resultado != NULL) {
        printf("Se encontró '%c' en la posición: %ld\n",
		caracter_a_buscar, resultado - cadena);
        // resultado - cadena calcula el índice (posición)
    } else {
        printf("No se encontró '%c'\n", caracter_a_buscar);
    }
    return 0;
}*/
