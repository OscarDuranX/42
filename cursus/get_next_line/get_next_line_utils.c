/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:33:22 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/26 22:47:24 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	while (ptr[i] && (ptr[i] != (unsigned char)c))
		i++;
	if (ptr[i] == (unsigned char)c)
		return (&ptr[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*joinstr;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	joinstr = (char *)malloc (sizeof(*s1) * (len + 1));
	if (!joinstr)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			joinstr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		joinstr[j++] = s2[i];
	joinstr[j] = '\0';
	return (free(s1), joinstr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = -1;
	while (++i < n)
		((unsigned char *)dest)[i] = ((unsigned char *) src)[i];
	return (dest);
}
