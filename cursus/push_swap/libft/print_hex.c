/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:34:28 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/19 22:28:01 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned int value, int asc)
{
	char			buffer[20];
	int				i;
	int				len;
	char			digit;
	unsigned int	d;

	len = 0;
	i = 0;
	if (value == 0)
		return (print_char('0'));
	while (value > 0)
	{
		d = value % 16;
		if (d < 10)
			digit = d + '0';
		else
			digit = d + asc;
		buffer[i++] = digit;
		value /= 16;
	}
	while (i--)
		len += print_char(buffer[i]);
	return (len);
}
