/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:22:29 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 18:24:32 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
/*int main() {
    char c1 = 'A';
    char c2 = '7';
    char c3 = '$';

    printf("Resultat fu: %d\n", isalnum(c1));
    if (ft_isalnum(c1)) {
        printf("'%c' es alfanumérico.\n", c1); // Imprimirá esto
    }
    printf("Resultat fu: %d\n", isalnum(c2));
    if (ft_isalnum(c2)) {
        printf("'%c' es alfanumérico.\n", c2); // Imprimirá esto
    }
    printf("Resultat fu: %d\n", isalnum(c3));
    if (!ft_isalnum(c3)) { // Si NO es alfanumérico
        printf("'%c' NO es alfanumérico.\n", c3); // Imprimirá esto
    }

    return 0;
}*/
