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

void push(t_stack *stack, long long data)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		return ;
	new_element->value = (int)data;
	new_element->next = stack->top;
	stack->top = new_element;
	stack->size++;
}

void free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
bool is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}
void print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
