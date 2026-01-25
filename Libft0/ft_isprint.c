/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:17:54 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/24 18:26:20 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int	ft_isprint(char c)
{
	printf("valor %d\n", c);
	if (c >= 0 && c <= 32 || c == 127)	
		return (0);
	else
		return (16384);
}

/*int main() {
    char c1 = 'A';
    char c2 = '\\'; // Espacio
    char c3 = '\t'; // Tabulación (no imprimible)

    printf("isprint('%c'): %d\n", c1, ft_isprint(c1)); // Devuelve no-cero (verdadero)
    printf("isprint('%c'): %d\n", c2, ft_isprint(c2)); // Devuelve no-cero (verdadero)
    printf("isprint('DEL'): %d\n", isprint(92));    // Devuelve cero (falso)

    return 0;
