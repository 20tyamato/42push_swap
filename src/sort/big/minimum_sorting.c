/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:17 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/30 11:59:24 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_steps_using_rb(t_stack *a, t_stack *b, int value);
int		count_steps_using_rrb(t_stack *a, t_stack *b, int value);

void	exec_operations(t_stack *a, t_stack *b, int value);
int		merge_operations(t_operation_count *operation_count);

static bool	is_out_of_range(t_stack *stack, int value)
{
	return (value > get_max_num_in_stack(stack)
		|| value < get_min_num_in_stack(stack));
}

void	calc_minimum_steps_for_a(t_stack *a, t_stack *b,
			t_operation_count *operation_count, int value)
{
	(void)b;
	operation_count->ra = get_position_from_top(a, value);
	operation_count->rra = a->size - get_position_from_top(a, value);
}

void	calc_minimum_steps_for_b(t_stack *a, t_stack *b,
			t_operation_count *operation_count, int value)
{
	if (is_out_of_range(b, value))
		operation_count->rb = get_position_from_top(b, get_max_num_in_stack(b));
	else
		operation_count->rb = count_steps_using_rb(a, b, value);
	if (is_out_of_range(b, value))
		operation_count->rrb = b->size
			- get_position_from_top(b, get_max_num_in_stack(b));
	else
		operation_count->rrb = count_steps_using_rrb(a, b, value);
}

int	calc_minimum_steps(t_stack *a, t_stack *b,
		t_operation_count *operation_count, int value)
{
	int	operation_sum;

	calc_minimum_steps_for_a(a, b, operation_count, value);
	calc_minimum_steps_for_b(a, b, operation_count, value);
	operation_sum = merge_operations(operation_count);
	return (operation_sum);
}

void	minimum_sorting(t_stack *a, t_stack *b)
{
	t_list				*current;
	t_operation_count	*operation_count;
	int					min_operations;
	int					min_operations_number;
	int					operation_sum;

	current = a->top;
	operation_count = init_operation_count();
	min_operations = INT_MAX;
	min_operations_number = current->value;
	while (current)
	{
		reset_operation_counts(operation_count);
		operation_sum = calc_minimum_steps(a, b,
				operation_count, current->value);
		if (min_operations > operation_sum)
		{
			min_operations = operation_sum;
			min_operations_number = current->value;
		}
		current = current->next;
	}
	exec_operations(a, b, min_operations_number);
	free(operation_count);
}
