/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:46:28 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/08 20:13:47 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_datacount *data)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->index;
	middle = (*a)->next->index;
	bottom = (*a)->next->next->index;
	if (top > middle && top < bottom)
		execute_operations(SA, a, NULL, data);
	else if (top > middle && middle > bottom)
	{
		execute_operations(SA, a, NULL, data);
		execute_operations(RRA, a, NULL, data);
	}
	else if (top > middle && middle < bottom)
		execute_operations(RA, a, NULL, data);
	else if (top < middle && middle > bottom && top < bottom)
	{
		execute_operations(SA, a, NULL, data);
		execute_operations(RA, a, NULL, data);
	}
	else if (top < middle && middle > bottom && top > bottom)
		execute_operations(RRA, a, NULL, data);
}

void	sort_four(t_stack **a, t_stack **b, t_datacount *data, int start_index)
{
	int	pos;

	pos = min_index_position(*a, start_index);
	if (pos == 1)
		execute_operations(RA, a, b, data);
	else if (pos == 2)
	{
		execute_operations(RA, a, b, data);
		execute_operations(RA, a, b, data);
	}
	else if (pos == 3)
		execute_operations(RRA, a, b, data);
	execute_operations(PB, a, b, data);
	sort_three(a, data);
	execute_operations(PA, a, b, data);
}

void	sort_five(t_stack **a, t_stack **b, t_datacount *data)
{
	int	pos;

	pos = min_index_position(*a, 0);
	if (pos == 1)
		execute_operations(RA, a, b, data);
	else if (pos == 2)
	{
		execute_operations(RA, a, b, data);
		execute_operations(RA, a, b, data);
	}
	else if (pos == 3)
	{
		execute_operations(RRA, a, b, data);
		execute_operations(RRA, a, b, data);
	}
	else if (pos == 4)
		execute_operations(RRA, a, b, data);
	execute_operations(PB, a, b, data);
	sort_four(a, b, data, 1);
	execute_operations(PA, a, b, data);
}

void	simple_sort(t_stack **a, t_stack **b, t_datacount *data)
{
	int	size;
	int	target_index;

	target_index = 0;
	size = stack_size(*a);
	while (size > 3)
	{
		move_to_top(a, b, data, target_index);
		target_index++;
		execute_operations(PB, a, b, data);
		size = stack_size(*a);
	}
	sort_three(a, data);
	while (*b)
		execute_operations(PA, a, b, data);
}
