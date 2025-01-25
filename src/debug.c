#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
