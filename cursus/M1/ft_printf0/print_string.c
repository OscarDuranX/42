/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:35:20 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/08 18:44:19 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_string("(null)"));
	while (str[i])
	{
		if (print_char(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
