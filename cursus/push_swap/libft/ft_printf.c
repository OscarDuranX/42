/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:21:59 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/19 22:27:01 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] && (ptr[i] != (unsigned char)c))
		i++;
	if (ptr[i] == (unsigned char)c)
		return (&ptr[i]);
	return (0);
}

int	check_type(const char *str, va_list arg, int j)
{
	int	i;

	i = 0;
	if (str[j] == 'c')
		i += print_char(va_arg(arg, int));
	else if (str[j] == 's')
		i += print_string(va_arg(arg, char *));
	else if (str[j] == 'p')
		i += print_pointer((unsigned long)va_arg(arg, void *));
	else if (str[j] == 'd')
		i += print_int(va_arg(arg, int));
	else if (str[j] == 'i')
		i += print_int(va_arg(arg, int));
	else if (str[j] == 'u')
		i += print_unsigned(va_arg(arg, unsigned int));
	else if (str[j] == 'x')
		i += print_hex(va_arg(arg, unsigned int), 87);
	else if (str[j] == 'X')
		i += print_hex(va_arg(arg, unsigned int), 55);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	unsigned int		count;
	va_list				args;
	int					i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (ft_strchr("cspdiuxX", str[i]))
				count += check_type(str, args, i);
			else if (str[i] == '%')
				count += print_char('%');
		}
		else if (str[i] == '%')
			return (-1);
		else
			count = count + print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
