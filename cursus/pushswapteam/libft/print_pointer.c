/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:45:18 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/19 22:28:36 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(unsigned long value)
{
	char		buffer[20];
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (value == 0)
		return (print_string("(nil)"));
	while (value > 0)
	{
		buffer[i++] = "0123456789abcdef"[value % 16];
		value /= 16;
	}
	len += print_string("0x");
	while (i--)
		len += print_char(buffer[i]);
	return (len);
}
