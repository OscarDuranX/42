/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:57:25 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/17 21:51:14 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	upcase;

	upcase = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && upcase == 0)
		{
			str[i] = str[i] - 32;
			upcase = 1;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
			upcase = 1;
		else
			upcase = 0;
	}
	return (str);
}
/*
int	main(void)
{
	char str[] = "salut,mots quarante-deux; cinquante+et+un";

	printf("Antes de la ft:\n%s\n", str);
	printf("Despues de la ft:\n%s\n", ft_strcapitalize(str));
	return (0);
}*/
