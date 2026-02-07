/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:43:02 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/02 15:55:04 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_impressora(int conx, int cony, int x, int y)
{
	if (conx == 1 && cony == 1)
	{
		ft_putchar ('A');
	}
	else if ((conx == x && cony == 1) || (cony == y && conx == 1))
	{
		ft_putchar ('C');
	}
	else if ((conx < x && cony == 1) || (conx == 1 && cony < y) || (conx == x && cony < y) || (cony == y && conx < x))
	{
		ft_putchar ('B');
	}
	else if (conx < x && cony < y)
	{
		ft_putchar (' ');
	}
	else
	{
		ft_putchar ('A');
	}
}

void	rush(int x, int y)
{
	int	conx;
	int	cony;

	if (x <= 0 || y <= 0 || x >= 2147483647 || y >= 2147483647)
		return ;

	conx = 1;
	cony = 1;
	while (conx <= x && cony <= y)
	{
		while (conx <= x)
		{
			ft_impressora (conx, cony, x, y);
			++conx;
		}
		ft_putchar ('\n');
		++cony;
		conx = 1;
	}
}
