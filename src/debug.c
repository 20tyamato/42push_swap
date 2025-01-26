#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	if (!current)
	{
		printf("empty\n");
		return ;
	}
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
