/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 09:31:02 by smilla-c          #+#    #+#             */
/*   Updated: 2025/11/02 14:16:55 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_line(int x, char start, char middle, char end)

{
	int	i;

	if (x > 0)
		ft_putchar(start);
	i = 1;
	while (i < x -1)
	{
		ft_putchar(middle);
		i++;
	}
	if (x > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	else if (x >= 2147483647 || y >= 2147483647)
		return ;
	i = 1;
	while (i <= y)
	{
		if (i == 1)
			ft_line(x, 'A', 'B', 'C');
		else if (i == y)
			ft_line(x, 'C', 'B', 'A');
		else
			ft_line(x, 'B', ' ', 'B');
		i++;
	}
}
