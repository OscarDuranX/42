/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:18:58 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/20 15:52:06 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	else if (str[0] == '\0')
		return (NULL);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			++j;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
	}
	return (NULL);
}
/*
int	main(void)
{
	char str[] = "";
	char to_find[] = "";

	printf("Resultat find: %p\n", ft_strstr(str, to_find));
}*/
