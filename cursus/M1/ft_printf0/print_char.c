/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:32:19 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/09 20:47:01 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char word)
{
	if (!write (1, &word, 1))
		return (-1);
	return (1);
}
/*int	print_char(char word)
{
	ft_putchar_fd(word, 1);
	return (1);
}*/
