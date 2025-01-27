#include "push_swap.h"

int get_max_position(t_stack *a)
{
	t_list *current;
	int i;

	current = a->top;
	i = 0;
	while (current)
	{
		if (current->value == get_max_num_in_stack(a))
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
		while (a->top->value != get_max_num_in_stack(a))
			forward_rotate_a(a, b);
	}
	else
	{
		while (a->top->value != get_max_num_in_stack(a))
			reverse_rotate_a(a, b);
	}
}
