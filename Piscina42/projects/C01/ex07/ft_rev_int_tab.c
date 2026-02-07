/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:33:56 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/12 16:28:11 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temporal;
	int	con;

	con = 0;
	while (con < size / 2)
	{
		temporal = tab[con];
		tab[con] = tab[size - 1 - con];
		tab[size - 1 - con] = temporal;
		con++;
	}
}
/*
int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5};
	int	size;

	size = 5;
	printf ("cadena int antes: %d \n", tab[0]);
	ft_rev_int_tab (tab, size);
	printf ("cadena int despues: %d \n", tab[0]);
	return (0);
}*/
