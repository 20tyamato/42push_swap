/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:23 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:24 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_minimum_steps(t_stack *a, t_stack *b,
		t_operation_count *operation_count, int value);

void	repeat_operation(void (*operation)(t_stack *, t_stack *),
								t_stack *a, t_stack *b, int count)
{
	while (count-- > 0)
		operation(a, b);
}

t_operation_count	*init_operation_count(void)
{
	t_operation_count	*operation_count;

	operation_count = (t_operation_count *)malloc(sizeof(t_operation_count));
	if (!operation_count)
		return (NULL);
	operation_count->ra = 0;
	operation_count->rb = 0;
	operation_count->rr = 0;
	operation_count->rra = 0;
	operation_count->rrb = 0;
	operation_count->rrr = 0;
	return (operation_count);
}

void	reset_operation_counts(t_operation_count *operation_count)
{
	operation_count->ra = 0;
	operation_count->rb = 0;
	operation_count->rr = 0;
	operation_count->rra = 0;
	operation_count->rrb = 0;
	operation_count->rrr = 0;
}

void	exec_operations(t_stack *a, t_stack *b, int value)
{
	t_operation_count	*op_count;

	op_count = init_operation_count();
	calc_minimum_steps(a, b, op_count, value);
	repeat_operation(forward_rotate_a, a, b, op_count->ra);
	repeat_operation(forward_rotate_b, a, b, op_count->rb);
	repeat_operation(forward_rotate_ab, a, b, op_count->rr);
	repeat_operation(reverse_rotate_a, a, b, op_count->rra);
	repeat_operation(reverse_rotate_b, a, b, op_count->rrb);
	repeat_operation(reverse_rotate_ab, a, b, op_count->rrr);
	push_b(a, b);
	free(op_count);
}

void	print_operation_count(t_operation_count *operation_count)
{
	ft_putstr_fd("=======================================\n", STDOUT_FILENO);
	ft_putstr_fd("ra: ", STDOUT_FILENO);
	ft_putnbr_fd(operation_count->ra, STDOUT_FILENO);
	ft_putstr_fd("\nrb: ", STDOUT_FILENO);
	ft_putnbr_fd(operation_count->rb, STDOUT_FILENO);
	ft_putstr_fd("\nrr: ", STDOUT_FILENO);
	ft_putnbr_fd(operation_count->rr, STDOUT_FILENO);
	ft_putstr_fd("\nrra: ", STDOUT_FILENO);
	ft_putnbr_fd(operation_count->rra, STDOUT_FILENO);
	ft_putstr_fd("\nrrb: ", STDOUT_FILENO);
	ft_putnbr_fd(operation_count->rrb, STDOUT_FILENO);
	ft_putstr_fd("\nrrr: ", STDOUT_FILENO);
	ft_putnbr_fd(operation_count->rrr, STDOUT_FILENO);
	ft_putstr_fd("=======================================\n", STDOUT_FILENO);
}
