#include "push_swap.h"

int	get_max_num_in_stack(t_stack *stack)
{
	t_list	*current;
	int		max;

	current = stack->top;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_min_num_in_stack(t_stack *stack)
{
	t_list	*current;
	int		min;

	current = stack->top;
	min = INT_MAX;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}
