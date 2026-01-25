/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:50:32 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/13 18:14:06 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		i;

	i = -1;
	while (src[++i])
	{
	}
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (src[++i])
	{
		tmp[i] = src[i];
	}
	tmp[i] = '\0';
	return (tmp);
}
/*
int	main(void)
{
	char src[] = "holasi";
	char *tmp;

	tmp = ft_strdup(src);
	free(tmp);
	return (0);
}*/
