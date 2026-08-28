/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:35:35 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/10 16:34:26 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	printf("valor a: %d valor b: %d \n", a, b);
	ft_swap(&a, &b);
	printf("valor a: %d valor b: %d \n", a, b);
	return (0);
}*/
