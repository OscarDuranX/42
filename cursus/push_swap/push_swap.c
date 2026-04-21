/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:45:29 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/14 17:42:07 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_flag		opts;
	t_stack		*stack_a;

	init_flag(&opts);
	stack_a = NULL;
	if (argc <= 1)
		return (0);
	if (parseo(argc, argv, &opts, &stack_a))
	{
		ft_printf("Error\n");
		return (free_stack(&stack_a), 0);
	}
	value_index(&stack_a);
	if (swap_ejecution(&stack_a, &opts))
		ft_printf("Error ejec\n");
	return (0);
}
