/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:22:46 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/17 16:34:50 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
	}
	return (1);
}

/*int	main(void)
{
	char	*str;

	str = "as'\a'";
	printf ("valor ft: %d\n", ft_str_is_printable(str));
}*/
