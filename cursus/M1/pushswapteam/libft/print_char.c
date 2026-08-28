/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:32:19 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/19 22:27:43 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
