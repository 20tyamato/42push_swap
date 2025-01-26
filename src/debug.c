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
	printf("======================\n");
	printf("top\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("bottom\n");
	printf("======================\n");
}
