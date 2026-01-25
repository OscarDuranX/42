/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:17:44 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/18 21:51:16 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i])
	{
	}
	return (s1[i] - s2[i]);
}

void	ft_swapchar(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argc > ++i + 1)
	{
		j = i;
		while (argc > ++j)
			if (ft_strcmp (argv[i], argv[j]) > 0)
				ft_swapchar (&argv[i], &argv[j]);
	}
	i = 0;
	while (argc > ++i)
	{
		j = -1;
		while (argv[i][++j])
			ft_putchar(argv[i][j]);
		ft_putchar ('\n');
	}
	return (0);
}
