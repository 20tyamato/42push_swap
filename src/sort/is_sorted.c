#include "push_swap.h"

bool	is_sorted(t_stack *a, t_stack *b)
{
	t_list	*current;

	if (is_empty(b))
	{
		current = a->top;
		while (current->next)
		{
			if (current->value > current->next->value)
				return (false);
			current = current->next;
		}
	}
	return (true);
}
