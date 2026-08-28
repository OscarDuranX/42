/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:57:32 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/14 17:15:32 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	count;

	count = 0;
	while (a != NULL)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	radix_sort(t_stack **a, t_stack **b, t_datacount *data)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				execute_operations(RA, a, b, data);
			else
				execute_operations(PB, a, b, data);
		}
		while (stack_size(*b) != 0)
			execute_operations(PA, a, b, data);
	}
}
