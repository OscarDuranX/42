/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ejec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:18:44 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/14 17:42:26 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	select_simple(t_stack **a, t_stack **b, t_datacount *data)
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
		simple_sort(a, b, data);
}

int	swap_ejecution(t_stack **a, t_flag *flags)
{
	t_stack		*stack_b;
	t_datacount	datacount;
	double		disorder;

	disorder = disorder_index(*a) * 100;
	stack_b = NULL;
	init_datacount(&datacount);
	datacount.bench_mode = 1;
	if (disorder == 0)
		disorder = 0;
	else if (flags->method == METHOD_SIMPLE)
		select_simple(a, &stack_b, &datacount);
	else if (flags->method == METHOD_MEDIUM)
		chunks_sort(a, &stack_b, &datacount);
	else if (flags->method == METHOD_COMPLEX)
		radix_sort(a, &stack_b, &datacount);
	else if (flags->method == METHOD_ADAPTIVE)
		adaptative_alg(a, &stack_b, &datacount);
	if (flags->bench == 1)
		benchmark (flags, &datacount, disorder);
	return (free_stack(a), free_stack(&stack_b), 0);
}

void	value_index(t_stack **a)
{
	int			size;
	int			i;
	t_stack		*min_node;
	t_stack		*current;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		current = *a;
		min_node = NULL;
		while (current != NULL)
		{
			if (current->index == -1 && (min_node == NULL
					|| current->value < min_node->value))
				min_node = current;
			current = current->next;
		}
		if (min_node != NULL)
			min_node->index = i;
		i++;
	}
}
