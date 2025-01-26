#include "push_swap.h"

bool	is_empty(t_stack *stack);

bool	is_sorted(t_stack *a, t_stack *b)
{
	t_list	*current;

	(void)b;
	if (a == NULL || a->top == NULL)
		return (true);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
