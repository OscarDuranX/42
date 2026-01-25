/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:16:42 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 20:37:31 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int main() {
    char arr1[] = {1, 2, 3, 4, 5};
    char arr2[] = {1, 2, 3, 4, 5};
    char arr3[] = {1, 2, 3, 4, 6};
    int res1, res2, res3;

    // Comparar arr1 y arr2 (iguales)
    res1 = ft_memcmp(arr1, arr2, sizeof(arr1));
    printf("Comparando arr1 y arr2: %d\n", res1); // Salida: 0

    // Comparar arr1 y arr3 (arr3 es mayor)
    res2 = ft_memcmp(arr1, arr3, sizeof(arr1));
    printf("Comparando arr1 y arr3: %d\n", res2); // Salida: Negativo

    // Comparar arr3 y arr1 (arr3 es mayor)
    res3 = ft_memcmp(arr3, arr1, sizeof(arr1));
    printf("Comparando arr3 y arr1: %d\n", res3); // Salida: Positivo

    return 0;
}*/
