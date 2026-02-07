/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:55:23 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/19 17:46:02 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	con_leng(char *s1)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
	}
	return (i);
}

unsigned int	fn_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	leng_dest;
	unsigned int	leng_src;
	unsigned int	i;

	leng_dest = con_leng(dest);
	leng_src = con_leng(src);
	if (size <= leng_dest)
		return (size + leng_src);
	i = -1;
	while (src[++i] && leng_dest + i < size - 1)
		dest[leng_dest + i] = src[i];
	dest[leng_dest + i] = '\0';
	return (leng_dest + leng_src);
}
/*
int	main(void)
{
	char	src[] = "si no p";
	char	dest[] = "Buscasi";

	printf("Resultado ft: %d\n", fn_strlcat(dest, src, 10));
}*/
