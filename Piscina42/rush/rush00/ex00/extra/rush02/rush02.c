/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:17:51 by smilla-c          #+#    #+#             */
/*   Updated: 2025/11/02 13:22:47 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line_ver(int x, char start, char middle, char end)
{
	int	i;

	if (x > 0)
		ft_putchar (start);
	i = 1;
	while (i < x -1)
	{
		ft_putchar (middle);
		i++;
	}
	if (x > 1)
		ft_putchar (end);
	ft_putchar ('\n');
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
			print_line_ver (x, 'A', 'B', 'A');
		else if (i == y)
			print_line_ver (x, 'C', 'B', 'C');
		else
			print_line_ver (x, 'B', ' ', 'C');
		i++;
	}
}
