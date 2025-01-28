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

int	get_middle_num_in_stack(t_stack *stack)
{
	int		size;
	t_list	*current;
	int		i;

	size = stack->size;
	current = stack->top;
	if (size % 2 == 0)
		i = 0;
	else
		i = 1;
	while (i != size / 2)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

int	get_second_max_num_in_stack(t_stack *stack)
{
	t_list	*current;
	int		max;
	int		second_max;

	current = stack->top;
	max = INT_MIN;
	second_max = INT_MIN;
	while (current)
	{
		if (current->value > max)
		{
			second_max = max;
			max = current->value;
		}
		else if (current->value > second_max)
			second_max = current->value;
		current = current->next;
	}
	return (second_max);
}

int	get_second_min_num_in_stack(t_stack *stack)
{
	t_list	*current;
	int		min;
	int		second_min;

	current = stack->top;
	min = INT_MAX;
	second_min = INT_MAX;
	while (current)
	{
		if (current->value < min)
		{
			second_min = min;
			min = current->value;
		}
		else if (current->value < second_min)
			second_min = current->value;
		current = current->next;
	}
	return (second_min);
}
