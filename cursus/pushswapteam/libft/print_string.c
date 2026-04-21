/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:35:20 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/19 22:28:55 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
