/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:33:45 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/08 22:34:32 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	parse_flag(t_flag *opts, char *argv)
{
	if (!ft_strncmp(argv, "--simple", 9) && argv[8] == '\0')
		return (set_method(opts, METHOD_SIMPLE));
	else if (!ft_strncmp(argv, "--medium", 9) && argv[8] == '\0')
		return (set_method(opts, METHOD_MEDIUM));
	else if (!ft_strncmp(argv, "--complex", 10) && argv[9] == '\0')
		return (set_method(opts, METHOD_COMPLEX));
	else if (!ft_strncmp(argv, "--adaptive", 11) && argv[10] == '\0')
		return (set_method(opts, METHOD_ADAPTIVE));
	else if (!ft_strncmp(argv, "--bench", 8) && argv[7] == '\0')
	{
		if (opts->bench == 1)
			return (opts->error = 1, 1);
		opts->bench = 1;
		return (0);
	}
	opts->error = 1;
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**get_split(char *arg)
{
	char	**split;

	if (ft_strrchr(arg, ' ') != 0)
		return (ft_split(arg, ' '));
	split = malloc(sizeof(char *) * 2);
	if (!split)
		return (NULL);
	split[0] = ft_strdup(arg);
	if (!split[0])
		return (free_split(split), NULL);
	split[1] = NULL;
	return (split);
}

static int	is_valid(char *arg, t_stack **stack)
{
	int		i;
	int		flag;
	long	num;
	char	**split;

	flag = 0;
	split = get_split(arg);
	i = 0;
	while (split[i])
	{
		if (is_valid_int(split[i]))
			return (free_split(split), flag);
		num = ft_atol(split[i++], &flag);
		if (flag)
			return (free_split(split), 0);
		if (is_duplicate(*stack, (int)num))
			return (free_split(split), 0);
		if (!push_back(stack, (int)num))
			return (free_split(split), 0);
	}
	return (free_split(split), !flag);
}

int	parseo(int argc, char **argv, t_flag *opts, t_stack **stack)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "--", 2))
		{
			if (parse_flag(opts, argv[i]) != 0)
				return (1);
			if (opts->error)
				return (1);
		}
		else if (is_valid(argv[i], stack) == 0)
			return (1);
	}
	if (stack_size(*stack) == 0)
		return (1);
	if (opts->method == METHOD_NONE)
		opts->method = METHOD_ADAPTIVE;
	return (0);
}
