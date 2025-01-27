#include "push_swap.h"

int get_min_num_in_stack(t_stack *a)
{
	t_list *current;
	int min;

	current = a->top;
	min = INT_MAX;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int get_min_position(t_stack *a)
{
	t_list *current;
	int i;

	current = a->top;
	i = 0;
	while (current)
	{
		if (current->value == get_min_num_in_stack(a))
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void rev_sort_b(t_stack *a, t_stack *b)
{
	int min_position;
	int stack_size;

	min_position = get_min_position(b);
	stack_size = b->size;
	if (is_rev_sorted(b))
		return ;
	if (min_position < stack_size / 2)
	{
		while (b->top->value != get_min_num_in_stack(b))
			forward_rotate_b(a, b);
	}
	else
	{
		while (b->top->value != get_min_num_in_stack(b))
			reverse_rotate_b(a, b);
	}
}
