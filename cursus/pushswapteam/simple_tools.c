/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 20:11:25 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/14 17:02:09 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_stack **a, t_stack **b,
			t_datacount *data, int target_index)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	min_pos = min_index_position(*a, target_index);
	while (min_pos != 0)
	{
		if (min_pos <= size / 2)
			execute_operations(RA, a, b, data);
		else
			execute_operations(RRA, a, b, data);
		min_pos = min_index_position(*a, target_index);
	}
}

int	min_index_position(t_stack *a, int target_index)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index == target_index)
			return (pos);
		a = a->next;
		pos++;
	}
	return (0);
}
