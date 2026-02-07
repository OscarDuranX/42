/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:21:59 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/07 17:32:03 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *str, void *arg)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += print_char((char)arg);
	else if (*str == 's')
		i += print_string((char *)arg);
	else if (*str == 'p')
		i += print_pointer((unsigned long)arg, 87);
	else if (*str == 'd')
		i += print_int((int)arg);
	else if (*str == 'i')
		i += print_int((int)arg);
	else if (*str == 'u')
		i += print_unsigned((unsigned int)arg);
	else if (*str == 'x')
		i += print_hex((unsigned int)arg, 87);
	else if (*str == 'X')
		i += print_hex((unsigned int)arg, 55);
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
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX", *str))
				count += check_type(str, va_arg(args, void *));
			else if (*str == '%')
				count += print_char('%');
		}
		else
		{
			count = count + print_char(input);
			str++;
		}
	}
	va_end(args);
	return (count);
}
