/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:39:40 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 22:12:14 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	num;

	neg = 1;
	num = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i] - '0');
		else if (str[i] == '-' || str[i] == '+')
			return (0);
		++i;
	}
	return (num * neg);
}
/*
int main() {
    char *cadena1 = "123";
    char *cadena2 = " +45";
    char *cadena3 = "0";
    char *cadena4 = "  99"; // Espacios iniciales
    char *cadena5 = "100abc"; // Ignora lo que no es dígito

    int num1 = ft_atoi(cadena1);
    int num2 = ft_atoi(cadena2);
    int num3 = ft_atoi(cadena3);
    int num4 = ft_atoi(cadena4);
    int num5 = ft_atoi(cadena5);

    printf("'%s' -> %d\n", cadena1, num1); // Salida: '123' -> 123
    printf("'%s' -> %d\n", cadena2, num2); // Salida: '-45' -> -45
    printf("'%s' -> %d\n", cadena3, num3); // Salida: '0' -> 0
    printf("'%s' -> %d\n", cadena4, num4); // Salida: '  99' -> 99
    printf("'%s' -> %d\n", cadena5, num5); // Salida: '100abc' -> 100
    
    return 0;
}*/
