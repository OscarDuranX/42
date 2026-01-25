/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:34:13 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/24 18:54:33 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = start - 1;
	j = 0;	
	while (s[++i])
	{
		if (j < len)
		{
			str[j] = s[i];
			++j;
		}
	}
	str[j] = '\0';
	return (str);
}

int main() {
    char origen[] = "Explorando C en 2026";
    char destino[303]; // Asegúrate de que tenga espacio suficiente + 1 para el nulo '\0'
    
    // Queremos extraer "2026"
    // Comienza en el índice 16 y tiene 4 caracteres
    int inicio = 16;
    int longitud = 4;

    // strncpy(destino, origen + posición_inicio, longitud)
    destino = ft_substr(destino, inicio, longitud);


    printf("Texto original: %s\n", origen);
    printf("Subcadena extraída: %s\n", destino);

    return 0;
}
