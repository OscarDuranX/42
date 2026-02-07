/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:31 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/19 17:45:11 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (dest[++i])
	{
		j = 0;
	}
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "aleale";
	char	src[] = "entratot";

	printf("resultat final %s\n", ft_strncat(dest, src, 20));
	return (0);
}*/
