/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:34:17 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/05 18:07:28 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	first_node = *stack;
	second_node = (*stack)->next;
	tmp = first_node;
	first_node->next = second_node->next;
	second_node->next = tmp;
	*stack = second_node;
	return (1);
}

int	swap_ss(t_stack **a, t_stack **b)
{
	int	call_a;
	int	call_b;

	if (stack_size(*a) < 2 || stack_size(*b) < 2)
		return (0);
	call_a = swap(a);
	call_b = swap(b);
	return (1);
}
