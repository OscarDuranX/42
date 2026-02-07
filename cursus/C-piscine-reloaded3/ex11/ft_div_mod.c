/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:46:08 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/10 16:00:24 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 10;
	b = 2;
	div = 0;
	mod = -1;
	printf("Antes a: %d - b : %d - div %d - mod: %d\n", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("Despues a: %d - b : %d - div %d - mod: %d\n", a, b, div, mod);
	return (0);
}*/
