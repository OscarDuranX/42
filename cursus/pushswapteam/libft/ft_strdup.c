/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:06:15 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/03 02:13:54 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*tmp_str;
	size_t	i;

	tmp_str = (char *)malloc (sizeof(*s) * (ft_strlen(s) + 1));
	if (!tmp_str)
		return (NULL);
	i = -1;
	while (s[++i])
		tmp_str[i] = s[i];
	tmp_str[i] = '\0';
	return (tmp_str);
}
