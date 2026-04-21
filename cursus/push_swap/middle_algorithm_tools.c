/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_algorithm_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:48:32 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/14 16:54:15 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk_size(int size)
{
	int	res;

	if (size <= 100)
		res = (size / 5);
	else
		res = (size / 11);
	if (res == 0)
		return (1);
	return (res);
}

void	chunks_sort(t_stack **a, t_stack **b, t_datacount *data)
{
	if (stack_size(*a) == 2)
		execute_operations(SA, a, b, data);
	else if (stack_size(*a) == 3)
		sort_three(a, data);
	else if (stack_size(*a) == 4)
		sort_four(a, b, data, 0);
	else if (stack_size(*a) == 5)
		sort_five(a, b, data);
	else
		big_chunks_sort(a, b, data);
}
