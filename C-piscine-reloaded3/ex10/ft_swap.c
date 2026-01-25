/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:18:34 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/10 15:35:38 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 2;
	b = 5;
	printf("Antes a: %d - b: %d\n", a, b);
	ft_swap(&a, &b);
	printf("Despues a: %d - b: %d\n", a, b);
	return (0);
}*/
