/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:56:21 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/18 21:15:29 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define FILE_NAME_MISSING "File name missing.\n"
#define TOO_MANY_ARGUMENTS "Too many arguments.\n"
#define CANNOT_READ_FILE "Cannot read file.\n"

int	main(int argc, char **argv)
{
	int		fd;
	size_t	amount;
	char	buffer[512];

	if (argc == 1)
		return (write (2, FILE_NAME_MISSING, sizeof(FILE_NAME_MISSING) - 1));
	else if (argc > 2)
		return (write (2, TOO_MANY_ARGUMENTS, sizeof(TOO_MANY_ARGUMENTS) - 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, CANNOT_READ_FILE, sizeof(CANNOT_READ_FILE) - 1));
	amount = 1;
	while (amount > 0)
	{
		amount = read(fd, buffer, sizeof(buffer));
		write(1, buffer, amount);
	}
	close(fd);
	return (0);
}
