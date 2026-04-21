/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 15:40:57 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/14 16:53:02 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_chunks_sort(t_stack **a, t_stack **b, t_datacount *data)
{
	int	low;
	int	high;
	int	chunk_size;

	low = 0;
	chunk_size = calculate_chunk_size(stack_size(*a));
	high = chunk_size - 1;
	while (*a)
	{
		if ((*a)->index >= low && (*a)->index <= high)
		{
			execute_operations(PB, a, b, data);
			if (stack_size(*b) == high + 1)
			{
				low += chunk_size;
				high += chunk_size;
			}
		}
		else
			execute_operations(RA, a, b, data);
	}
	return_to_a(a, b, data);
}

void	return_to_a(t_stack **a, t_stack **b, t_datacount *data)
{
	int	max_pos;

	while (*b)
	{
		max_pos = max_index_position(*b);
		move_to_top_b(a, b, data, max_pos);
		execute_operations(PA, a, b, data);
	}
}

int	max_index_position(t_stack *b)
{
	int	current_pos;
	int	max_index;
	int	max_pos;

	current_pos = 0;
	max_index = -1;
	max_pos = 0;
	while (b)
	{
		if (b->index > max_index)
		{
			max_index = b->index;
			max_pos = current_pos;
		}
		b = b->next;
		current_pos++;
	}
	return (max_pos);
}

void	move_to_top_b(t_stack **a, t_stack **b, t_datacount *data, int max_pos)
{
	int	size;

	while (max_pos != 0)
	{
		size = stack_size(*b);
		if (max_pos <= size / 2)
		{
			execute_operations(RB, a, b, data);
		}
		else
		{
			execute_operations(RRB, a, b, data);
		}
		max_pos = max_index_position(*b);
	}
}
