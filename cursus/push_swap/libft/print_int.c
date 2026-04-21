/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:53:00 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/19 22:28:19 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_int_recursive(long num)
{
	if (num < 0)
	{
		print_char('-');
		num = (unsigned int)(num * -1);
	}
	if (num > 9)
		print_int_recursive(num / 10);
	print_char((char)(num % 10 + '0'));
}

int	print_int(int num)
{
	long	n;
	int		len;

	n = num;
	print_int_recursive(n);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}
