#include "push_swap.h"

void	exec_operations(t_stack *a, t_stack *b, int value);
int		merge_operations(t_operation_count *operation_count);

static bool	is_out_of_range(t_stack *stack, int value)
{
	return (value > get_max_num_in_stack(stack) || value < get_min_num_in_stack(stack));
}

// static bool is_between_borders(t_stack *stack, int value)
// {
// 	int bottom = get_bottom_element_of_stack(stack);
// 	int top    = get_top_element_of_stack(stack);

// 	return ((bottom < value && value < top) || (bottom > value && value > top));
// }

int	count_steps_using_rb(t_stack *a, t_stack *b, int value)
{
	int		count;
	t_stack	*tmp_b;

	(void)a;
	count = 0;
	tmp_b = copy_stack(b);
	if (is_out_of_range(b, value))
	{
		free_stack(tmp_b);
		return (get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (get_bottom_element_of_stack(tmp_b) == get_min_num_in_stack(tmp_b)
		|| get_top_element_of_stack(tmp_b) == get_max_num_in_stack(tmp_b))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
	}
	while (!(get_bottom_element_of_stack(tmp_b) < value
			&& value < get_top_element_of_stack(tmp_b))
		|| (get_bottom_element_of_stack(tmp_b) > value
			&& value > get_top_element_of_stack(tmp_b)))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return (-1);
		}
	}
	free_stack(tmp_b);
	return (count);
}

int	count_steps_using_rrb(t_stack *a, t_stack *b, int value)
{
	int		count;
	t_stack	*tmp_b;

	(void)a;
	count = 0;
	tmp_b = copy_stack(b);
	if (is_out_of_range(b, value))
	{
		free_stack(tmp_b);
		return (b->size - get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (get_bottom_element_of_stack(tmp_b) == get_min_num_in_stack(tmp_b)
		|| get_top_element_of_stack(tmp_b) == get_max_num_in_stack(tmp_b))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
	}
	while (!(get_bottom_element_of_stack(tmp_b) < value
			&& value < get_top_element_of_stack(tmp_b))
		|| (get_bottom_element_of_stack(tmp_b) > value
			&& value > get_top_element_of_stack(tmp_b)))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return (-1);
		}
	}
	free_stack(tmp_b);
	return (count);
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
	operation_count->rb = count_steps_using_rb(a, b, value);
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
