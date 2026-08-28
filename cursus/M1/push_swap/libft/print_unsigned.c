/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:56:24 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/19 22:29:13 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_unsigned_recursive(unsigned int num)
{
	if (num > 9)
		print_unsigned_recursive(num / 10);
	print_char((char)(num % 10 + '0'));
}

int	print_unsigned(unsigned int num)
{
	unsigned int	nb;
	int				len;

	nb = num;
	len = 0;
	if (num == 0)
	{
		return (print_char('0'));
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	print_unsigned_recursive(num);
	return (len);
}
