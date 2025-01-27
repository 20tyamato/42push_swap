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

void	free_stack(t_stack *stack)
{
	while (stack->top != NULL)
		pop(stack);
	free(stack);
}

bool	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

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

void	push(t_stack *stack, int data)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		return ;
	new_element->value = data;
	new_element->next = stack->top;
	stack->top = new_element;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		data;

	if (stack->top == NULL)
		return (-1);
	tmp = stack->top;
	stack->top = stack->top->next;
	data = tmp->value;
	free(tmp);
	stack->size--;
	return (data);
}
