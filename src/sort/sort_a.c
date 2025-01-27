#include "push_swap.h"

int get_max(t_stack *a)
{
	t_list *current;
	int max;

	current = a->top;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int get_max_position(t_stack *a)
{
	t_list *current;
	int i;

	current = a->top;
	i = 0;
	while (current)
	{
		if (current->value == get_max(a))
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	sort_a(t_stack *a, t_stack *b)
{
	int max_position;
	int stack_size;

	max_position = get_max_position(a);
	stack_size = a->size;
	if (is_sorted(a))
		return ;
	if (max_position < stack_size / 2)
	{
		while (a->top->value != get_max(a))
			forward_rotate_a(a, b);
	}
	else
	{
		while (a->top->value != get_max(a))
			reverse_rotate_a(a, b);
	}
}
