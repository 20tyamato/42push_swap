#include "push_swap.h"

void	minimum_sorting(t_stack *a, t_stack *b);

void	forward_rotate_sort_a(t_stack *a, t_stack *b)
{
	int	max_position;
	int	stack_size;

	max_position = get_position_from_top(a, get_max_num_in_stack(a)) + 1;
	stack_size = a->size;
	if (is_sorted(a))
		return ;
	if (max_position < stack_size / 2)
		repeat_operation(forward_rotate_a, a, b, max_position);
	else
		repeat_operation(reverse_rotate_a, a, b, stack_size - max_position);
}

void	rev_rotate_sort_b(t_stack *a, t_stack *b)
{
	int	min_position;
	int	stack_size;

	min_position = get_position_from_top(b, get_min_num_in_stack(b)) + 1;
	stack_size = b->size;
	if (is_rev_sorted(b))
		return ;
	if (min_position < stack_size / 2)
		repeat_operation(forward_rotate_b, a, b, min_position);
	else
		repeat_operation(reverse_rotate_b, a, b, stack_size - min_position);
}

int	get_next_biggest_num(t_stack *a, int value)
{
	t_list	*current;
	int		next_biggest;

	current = a->top;
	next_biggest = INT_MAX;
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
	int	steps;

	steps = 0;
	while (b->size > 0)
	{
		steps = get_position_from_top(a,
				get_next_biggest_num(a, b->top->value));
		if (steps > a->size / 2)
			repeat_operation(reverse_rotate_a, a, b, a->size - steps);
		else
			repeat_operation(forward_rotate_a, a, b, steps);
		push_a(a, b);
	}
	forward_rotate_sort_a(a, b);
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	repeat_operation(push_b, a, b, 2);
	repeat_operation(minimum_sorting, a, b, a->size - 3);
	sort_small_stack(a, b);
	rev_rotate_sort_b(a, b);
	insert_b_to_a(a, b);
}
