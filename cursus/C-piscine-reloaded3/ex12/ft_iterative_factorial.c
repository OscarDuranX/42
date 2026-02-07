/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:11:08 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/18 21:43:49 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	tmp;

	result = 1;
	tmp = 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (tmp <= nb)
	{
		result *= tmp;
		tmp++;
	}
	return (result);
}
/*
int	main(void)
{
	printf("resultat: %d\n", ft_iterative_factorial(10));
}*/
