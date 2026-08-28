/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:13:00 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/04 01:50:17 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	is_delim(char c, char delim)
{
	return (c == delim);
}

static int	count_words(const char *str, char delim)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_delim(*str, delim))
			str++;
		if (*str)
		{
			count++;
			while (*str && !is_delim(*str, delim))
				str++;
		}
	}
	return (count);
}

static char	*alloc_word(const char *str, char delim)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	i = 0;
	while (str[len] && !is_delim(str[len], delim))
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_all(char **result, int i)
{
	while (i >= 0)
		free(result[i--]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && is_delim(*s, c))
			s++;
		if (*s)
		{
			result[i] = alloc_word(s, c);
			if (!result[i])
				return (free_all(result, i - 1), NULL);
			i++;
			while (*s && !is_delim(*s, c))
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}
