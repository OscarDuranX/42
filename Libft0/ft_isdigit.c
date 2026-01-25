/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:21:40 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 18:21:50 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
