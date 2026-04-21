/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:46:38 by oduran-m          #+#    #+#             */
/*   Updated: 2026/04/10 20:27:03 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>

typedef enum e_method
{
	METHOD_NONE = 0,
	METHOD_SIMPLE,
	METHOD_MEDIUM,
	METHOD_COMPLEX,
	METHOD_ADAPTIVE
}	t_method;

typedef struct s_flag
{
	t_method	method;
	int			bench;
	int			error;
}	t_flag;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	int				index;
/*	int	pos;//posicion que esta actualmente en el stack (0,1,2)
	int	cost_a;//cuantos movimientos cuesta subir el nodo al tope de a 
	int	cost_b;//lo mismo pero con b, el qe tenga la
	 suma mas baja es el que movemos
	int	target_pos//Si vas a mover un número del Stack A al Stack B, 
	¿en qué hueco exacto debe encajar para que B siga ordenado? y viceversa */
}	t_stack;

typedef enum e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_operations; /*IDs para los movimientos,on tipo de datos, 
no valiables no hayq que inicializarlo. el compilador le asigna un num 
permanente a cada ID (esa es su "inicializacion"), pero usaremos SA,
etc en vez el nuero para mejor lectura para nosotros. 
Este ID se le pasa a la funcion execute para que llame al 
movimiento que corresponda y o lo sume para bench o lo imprima en stout*/

typedef struct s_datacount
{
	int	bench_mode;//0 si no lo usamos y 1 si usamos --bench
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_operations;
}	t_datacount; // son variables, se inicializa poniendo todo a 0 en el inits.c
//parseo.c
int		parseo(int argc, char **argv, t_flag *opts, t_stack **stack);
//parseo_tools.c
int		set_method(t_flag *opts, t_method m);
int		is_valid_int(char *str);
int		is_duplicate(t_stack *stack, int value);
//init.c
void	init_flag(t_flag *flags);
int		push_back(t_stack **stack, int value);
void	init_datacount(t_datacount *data);
//index.c
double	disorder_index(t_stack *a);
void	print_op_name(t_operations operation);
void	execute_operations(t_operations operation,
			t_stack **a, t_stack **b, t_datacount *data);
void	show_operations(t_operations operation, t_datacount *data);
void	update_data_count(t_operations operation, t_datacount *data);
//push_operatios.c
int		push_a(t_stack **b, t_stack **a);
int		push_b(t_stack **a, t_stack **b);
//rotate_operations.c
int		rotate(t_stack **stack);
int		rotate_rr(t_stack **a, t_stack **b);
int		reverse_rotate(t_stack **stack);
int		rotate_rrr(t_stack **a, t_stack **b);
//swap_operations.c
int		swap(t_stack **stack);
int		swap_ss(t_stack **a, t_stack **b);
//simple_algorithm.c
void	sort_three(t_stack **a, t_datacount *data);
void	sort_four(t_stack **a, t_stack **b, t_datacount *data, int start_index);
void	sort_five(t_stack **a, t_stack **b, t_datacount *data);
void	move_to_top(t_stack **a, t_stack **b, t_datacount *data,
			int target_index);
void	simple_sort(t_stack **a, t_stack **b, t_datacount *data);
int		min_index_position(t_stack *a, int target_index);
//middle_algorithm.c
void	chunks_sort(t_stack **a, t_stack **b, t_datacount *data);
void	big_chunks_sort(t_stack **a, t_stack **b, t_datacount *data);
void	return_to_a(t_stack **a, t_stack **b, t_datacount *data);
int		max_index_position(t_stack *b);
void	move_to_top_b(t_stack **a, t_stack **b, t_datacount *data, int max_pos);
int		calculate_chunk_size(int size);
//complex_algorithm.c
int		stack_size(t_stack *a);
void	radix_sort(t_stack **a, t_stack **b, t_datacount *data);
//adaptative_algorithm.c
void	adaptative_alg(t_stack **a, t_stack **b, t_datacount *data);
//push_swap_ejec.c
int		swap_ejecution(t_stack **a, t_flag *flags);
void	value_index(t_stack **a);
void	select_simple(t_stack **a, t_stack **b, t_datacount *data);
void	free_stack(t_stack **stack);
//bench.c
void	benchmark(t_flag *flags, t_datacount *data, double disorder);

#endif
