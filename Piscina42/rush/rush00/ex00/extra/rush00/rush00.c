/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:26:54 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/02 15:41:46 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printlinea_esquina(int fx)
{
	int	con;

	ft_putchar ('o');
	con = fx - 2;
	while (con > 0)
	{
		ft_putchar ('-');
		--con;
	}
	if (fx != 1)
		ft_putchar ('o');
	ft_putchar ('\n');
}

void	ft_printcentro(int fx, int fy)
{
	int	altura;
	int	anchura;

	altura = fy -2;
	while (altura > 0)
	{
		ft_putchar ('|');
		anchura = fx - 2;
		while (anchura > 0)
		{
			ft_putchar (' ');
			--anchura;
		}
		if (fx != 1)
			ft_putchar ('|');
		ft_putchar ('\n');
		--altura;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	else if (x >= 2147483647 || y >= 2147483647)
		return ;
	ft_printlinea_esquina (x);
	ft_printcentro (x, y);
	if (y != 1)
		ft_printlinea_esquina (x);
}
