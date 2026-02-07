/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:55:53 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/13 19:25:04 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	dest[21];
	char	*src;
	char	*ex;

	src = "hola paco, apruebame";
	printf ("String dest inici: %s \n", dest);
	ex = ft_strcpy (dest, src);
	printf ("String dest final: %s \n", dest);
	return (0);
}*/
