/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:39:40 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/08 22:08:37 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long	ft_atol(const char *str, int *flag)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == ' ') || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
		if (str[i++] == '-')
			sign *= -1;
	str += i;
	i = 0;
	while ((str[i] >= '0') && (str[i] <= '9') && *flag == 0)
	{
		res = res * 10 + str[i] - '0';
		*flag = res > (long)INT_MAX || res < (long)INT_MIN;
		i++;
	}
	*flag = *flag || i == 0;
	return (res * sign);
}
