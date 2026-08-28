/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:31:56 by oduran-m          #+#    #+#             */
/*   Updated: 2026/03/10 21:16:38 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_good_line(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (str == NULL || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, str, i);
	tmp[i] = '\0';
	return (tmp);
}

char	*get_bad_line(char *str, int start)
{
	char	*tmp;
	int		i;
	size_t	len;
	size_t	str_len;

	if (!str || start < 0)
		return (NULL);
	str_len = ft_strlen(str);
	if ((size_t)start >= str_len)
		return (NULL);
	len = str_len - (size_t)start;
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[start])
		tmp[i++] = str[start++];
	tmp[i] = '\0';
	return (tmp);
}

char	*get_read_line(int fd, char *stash)
{
	ssize_t	amount;
	char	*buffer;
	char	*old;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	amount = 1;
	while (!ft_strchr(stash, '\n') && amount > 0)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount < 0)
			return (free(buffer), free(stash), NULL);
		buffer[amount] = '\0';
		old = stash;
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(old), free(buffer), NULL);
		free(old);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;

	if (fd < 0)
		return (NULL);
	stash = get_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = get_good_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	tmp = stash;
	stash = get_bad_line(stash, ft_strlen(line));
	return (free(tmp), line);
}
/*
int main(void)
{
    int     fd;
    char    *line;

    fd = open("hola", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
//        printf("Resultat:\n%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}*/
