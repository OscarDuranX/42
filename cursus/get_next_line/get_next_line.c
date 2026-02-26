/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:31:56 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/26 20:30:35 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
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

/*
void * => NULL == 0x0 == 0
char => '\0' == 0
NULL != '\0'
*/

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

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	size_t		amount;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	amount = 1;
	while (!ft_strchr(stash, '\n') && amount > 0)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount < 0)
			return (free(buffer), NULL);
		buffer[amount] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	line = get_good_line(stash);
	if (!line)
		return (free(buffer), NULL);
	stash = get_bad_line(stash, ft_strlen(line));
	free(buffer);
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("hola", O_RDONLY);
	printf("Resultat: \n%s\n", get_next_line(fd));
	printf("Resultat: \n%s\n", get_next_line(fd));
	printf("Resultat: \n%s\n", get_next_line(fd));
	printf("Resultat: \n%s\n", get_next_line(fd));
	printf("Resultat: \n%s\n", get_next_line(fd));
	printf("Resultat: \n%s\n", get_next_line(fd));
	close(fd);
	return (0);
}*/
