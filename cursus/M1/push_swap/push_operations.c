/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:47:46 by sayala-c          #+#    #+#             */
/*   Updated: 2026/04/14 16:42:58 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack **b, t_stack **a)
{
	t_stack	*move_node;
	t_stack	*first_b;
	t_stack	*first_a;

	if (*b == NULL)
		return (0);
	first_a = *a;
	first_b = *b;
	move_node = first_b;
	*b = (*b)->next;
	move_node->next = first_a;
	*a = move_node;
	return (1);
}

int	push_b(t_stack **a, t_stack **b)
{
	t_stack	*move_node;
	t_stack	*first_b;
	t_stack	*first_a;

	if (*a == NULL)
		return (0);
	first_a = *a;
	first_b = *b;
	move_node = first_a;
	*a = (*a)->next;
	move_node->next = first_b;
	*b = move_node;
	return (1);
}
