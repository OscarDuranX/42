/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:01:44 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/19 17:38:01 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/*int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "hola, como";
	s2 = "hola, como estas?";
	printf("comparacion s1 i s2: %d\n", ft_strcmp(s1, s2));
	return (0);
}*/
