#include "push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*new_stack;
	t_list	*current;

	new_stack = create_stack();
	if (new_stack == NULL)
		return (NULL);
	current = stack->top;
	while (current != NULL)
	{
		push(new_stack, current->value);
		current = current->next;
	}
	return (new_stack);
}

int	get_position_from_top(t_stack *stack, int value)
{
	t_list	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		if (current->value == value)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

int	get_top_element_of_stack(t_stack *stack)
{
	if (stack->top)
		return (stack->top->value);
	return (INT_MIN);
}

int	get_bottom_element_of_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current->next)
		current = current->next;
	return (current->value);
}
