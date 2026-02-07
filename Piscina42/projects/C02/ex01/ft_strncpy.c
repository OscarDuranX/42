/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:36:59 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/18 00:34:50 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[21];
	char	*src;
	int	n;

	n = 4;
	src = "pacooo noooo porqueee?";
	printf ("Dest antes: %s\n", dest);
	ft_strncpy(dest, src, n);
	printf ("Dest despues: %s\n", dest);
	return (0);
}*/
