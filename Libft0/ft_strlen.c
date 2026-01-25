/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:26:13 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 18:28:28 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
	{
	}
	return (i);
}
/*int main() {
    char miCadena[] = "";
    size_t longitud; // Usar size_t para almacenar el resultado

    longitud = ft_strlen(miCadena); // Calcular la longitud

    printf("Cadena \"%s\" tiene %zu char.\n", miCadena, longitud);

    return 0;
}*/
