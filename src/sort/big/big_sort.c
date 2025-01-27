#include "push_swap.h"

t_operation_count	*init_operation_count(void);
void				forward_rotate_sort_a(t_stack *a, t_stack *b);
void				rev_rotate_sort_b(t_stack *a, t_stack *b);
void				sort_small_stack(t_stack *a, t_stack *b);
int					get_top_element_of_stack(t_stack *stack);
int					get_bottom_element_of_stack(t_stack *stack);
int					get_max_num_in_stack(t_stack *stack);
int					get_min_num_in_stack(t_stack *stack);
int					merge_operations(t_operation_count *operation_count);
void				rev_sort_stack_of_two(t_stack *a, t_stack *b);
void				sort_stack_of_three(t_stack *a, t_stack *b);
int					get_position_from_top(t_stack *a, int value);
void				print_operation_count(t_operation_count *operation_count);

void				exec_operations(t_stack *a, t_stack *b, int value);
void				reset_operation_count(t_operation_count *operation_count);
void				repeat_operation(void (*op)(t_stack *, t_stack *),
								t_stack *a, t_stack *b, int count);

void	calc_minimum_steps_for_a(t_stack *a, t_stack *b, t_operation_count *operation_count, int value)
{
	(void)b;
	operation_count->ra = get_position_from_top(a, value);
	operation_count->rra = a->size - get_position_from_top(a, value);
}

int	count_steps_using_rb(t_stack *a, t_stack *b, int value)
{
	int		count;
	t_stack	*tmp_b;

	(void)a;
	count = 0;
	tmp_b = copy_stack(b);
	if (value > get_max_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (value < get_min_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (get_bottom_element_of_stack(tmp_b) == get_min_num_in_stack(tmp_b) || get_top_element_of_stack(tmp_b) == get_max_num_in_stack(tmp_b))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
	}
	while (!(get_bottom_element_of_stack(tmp_b) < value && value < get_top_element_of_stack(tmp_b)) || (get_bottom_element_of_stack(tmp_b) > value && value > get_top_element_of_stack(tmp_b)))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return -1;
		}
	}
	free_stack(tmp_b);
	return (count);
}

int count_steps_using_rrb(t_stack *a, t_stack *b, int value)
{
	(void)a;
	int count = 0;
	t_stack *tmp_b = copy_stack(b);
	if (value > get_max_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (b->size - get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (value < get_min_num_in_stack(b))
	{
		free_stack(tmp_b);
		return (b->size - get_position_from_top(b, get_max_num_in_stack(b)));
	}
	if (get_bottom_element_of_stack(tmp_b) == get_min_num_in_stack(tmp_b) || get_top_element_of_stack(tmp_b) == get_max_num_in_stack(tmp_b))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
	}
	while (!(get_bottom_element_of_stack(tmp_b) < value && value < get_top_element_of_stack(tmp_b)) || (get_bottom_element_of_stack(tmp_b) > value && value > get_top_element_of_stack(tmp_b)))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return -1;
		}
	}
	free_stack(tmp_b);
	return (count);
}

void	calc_minimum_steps_for_b(t_stack *a, t_stack *b, t_operation_count *operation_count, int value)
{
	operation_count->rb = count_steps_using_rb(a, b, value);
	operation_count->rrb = count_steps_using_rrb(a, b, value);
}

void	minimum_sorting(t_stack *a, t_stack *b)
{
	t_list				*current;
	t_operation_count	*operation_count;
	int					min_operations;
	int					min_operations_number;
	int operation_sum;

	current = a->top;
	operation_count = init_operation_count();
	min_operations = INT_MAX;
	min_operations_number = current->value;
	while (current)
	{
		reset_operation_count(operation_count);
		calc_minimum_steps_for_a(a, b, operation_count, current->value);
		calc_minimum_steps_for_b(a, b, operation_count, current->value);
		operation_sum = merge_operations(operation_count);
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

int get_next_biggest_num(t_stack *a, int value)
{
	t_list *current = a->top;
	int next_biggest = INT_MAX;

	while (current)
	{
		if (current->value > value && current->value < next_biggest)
			next_biggest = current->value;
		current = current->next;
	}
	return (next_biggest);
}

void	insert_b_to_a(t_stack *a, t_stack *b)
{
	t_list	*current;
	int		steps;

	current = b->top;
	steps = 0;
	while (current)
	{
		if (current->value > get_max_num_in_stack(a))
		{
			push_a(a, b);
			forward_rotate_a(a, b);
			continue;
		}
		steps = get_position_from_top(a, get_next_biggest_num(a, current->value));
		if (steps > a->size / 2)
		{
			steps = a->size - steps;
			while (steps-- > 0)
				reverse_rotate_a(a, b);
		}
		else
		{
			while (steps-- > 0)
				forward_rotate_a(a, b);
		}
		push_a(a, b);
		forward_rotate_sort_a(a, b);
		if (b->size == 1)
			break;
		current = b->top;
	}
	push_a(a, b);
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);

	while (a->size > 3)
	{
		// print_stack_side_by_side(a, b);
		minimum_sorting(a, b);
		// print_stack_side_by_side(a, b);
		// if (a->size == 3) // ここを変えることでデバッグできる
		// 	exit(0);
	}
	sort_stack_of_three(a, b);
	rev_rotate_sort_b(a, b);
	insert_b_to_a(a, b);
}

// 5 2 7 1 6 3 9 4 8

// pb
// pb
// 7 2
// 1 5
// 6
// 3
// 9
// 4
// 8
// rb
// 7 5
// 1 2
// 6
// 3
// 9
// 4
// 8
// pb
// pb

// 6 1
// 3 7
// 9 5
// 4 2
// 8

// rb
// rb
// pb


// 3 6
// 9 5
// 4 2
// 8 1
//   7
// rra
// rrb
// 8 7
// 3 6
// 9 5
// 4 2
//   1
// rrr????
// 4 1
// 8 7
// 3 6
// 9 5
//   2
// pb
// sa
// ra
// rra
// pa
// rra
// rra
// ra
// ra
// pa
// rra
// rra
// ra
// ra
// pa
// rra
// rra
// ra
// ra
// pa
// rra
// rra
// pa
// pa
