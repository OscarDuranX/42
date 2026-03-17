/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:59:18 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/09 23:05:54 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(char word);
int	print_hex(unsigned int value, int asc);
int	print_int(int num);
int	print_pointer(unsigned long value);
int	print_string(char *str);
int	print_unsigned(unsigned int num);

#endif
