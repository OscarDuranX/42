/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:21:59 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/09 21:02:39 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += print_char(va_arg(args, int));
	else if (*str == 's')
		i += print_string(va_arg(args, char *));
	else if (*str == 'p')
		i += print_pointer(va_arg(args, unsigned long));
	else if (*str == 'd')
		i += print_int(va_arg(args, int));
	else if (*str == 'i')
		i += print_int(va_arg(args, int));
	else if (*str == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x')
		i += print_hex(va_arg(args, unsigned int), 87);
	else if (*str == 'X')
		i += print_hex(va_arg(args, unsigned int), 55);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && (*str + 1) != '\0')
		{
			str++;
			if (ft_strchr("cspdiuxX", *str))
				count += check_type(str, args);
			else if (*str == '%')
				count += print_char('%');
		}
		else if (*str == '%')
			return (-1);
		else
			count = count + print_char(*str);
		str++;
	}
	va_end(args);
	return (count);
}
