/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:45:18 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/08 18:54:28 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long value)
{
	static char	hex[17] = "0123456789abcdef";
	char		buffer[20];
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (value == 0)
		return (print_string("(nil)"));
	while (value > 0)
	{
		buffer[i++] = hex[value % 16];
		value /= 16;
	}
	len += print_string("0x");
	while (i--)
		len += print_char(buffer[i]);
	return (len);
}
