/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:39:52 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 21:11:56 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *)s1);
	i = -1;
	while (s1[++i] && (size_t)i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i - 1]);
			j++;
		}
	}
	return (0);
}
/*
int main() {
    const char *cadena_principal = "Hola mundo, este es un ejemplo.";
    const char *subcadena = "mundo";
    const char *no = "adios";
    
    // Buscar "mundo" en la cadena principal, limitado a 20 caracteres
    char *resultado = ft_strnstr(cadena_principal, subcadena, 20); 
    
    if (resultado) {
        printf("Subcadena '%s' encontrada en: %s\n", subcadena, resultado);
    } else {
        printf("Subcadena '%s' no encontrada.\n", subcadena);
    }
    
    // Buscar "adios"
    resultado = ft_strnstr(cadena_principal, no, strlen(cadena_principal));
    if (!resultado) {
        printf("Subcadena '%s' no encontrada.\n", no);
    }

    return 0;
}*/
