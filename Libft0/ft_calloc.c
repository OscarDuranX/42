/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:34:31 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/24 18:01:55 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	void			*ptr;
	unsigned char	*tmp_ptr;

	ptr = (void *)malloc (num * size);
	if (!ptr)
		return (NULL);
	tmp_ptr = (unsigned char *)ptr;
	while (size--)
		*(tmp_ptr++) = '\0';
	return (ptr);
}
/*
int main() {
    int n, i;
    int *arreglo;

    printf("Introduce el número de elementos: ");
    scanf("%d", &n);

    // 1. Asignar memoria con calloc
    // Reserva espacio para 'n' elementos de tamaño 'int'
    arreglo = (int*) ft_calloc(n, sizeof(int));

    // 2. Verificar si la asignación fue exitosa
    if (arreglo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1; 
    }

    // 3. Comprobar que los valores iniciales son 0
    printf("\nValores inicializados por calloc:\n");
    for (i = 0; i < n; i++) {
        printf("arreglo[%d] = %d\n", i, arreglo[i]);
    }

    // 4. Llenar el arreglo y mostrarlo
    printf("\nIntroduce %d números:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    printf("\nEl arreglo final es:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }

    // 5. SIEMPRE liberar la memoria
    free(arreglo);
    printf("\n\nMemoria liberada correctamente.\n");

    return 0;
}*/
