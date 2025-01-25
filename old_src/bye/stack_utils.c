#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->top = NULL;
	return (new_stack);
}

void	clear_stack(t_stack **s)
{
	t_node	*current;
	t_node	*next;

	current = (*s)->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	(*s)->top = NULL;
}

int	is_stack_empty(t_stack *s)
{
	if (s->top == NULL)
		return (1);
	else
		return (0);
}

size_t	stack_size(t_stack *s)
{
	size_t	size;
	t_node	*current;

	size = 0;
	current = s->top;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

t_node	*create_node(int data)
{
	t_node	*new_element;

	new_element = (t_node *)malloc(sizeof(t_node));
	if (new_element == NULL)
		return (NULL);
	new_element->data = data;
	new_element->next = NULL;
	return (new_element);
}
