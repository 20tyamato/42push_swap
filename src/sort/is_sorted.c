#include "push_swap.h"

bool	is_a_sorted(t_stack *a, t_stack *b)
{
	t_list	*current;

	(void)b;
	if (a == NULL || a->top == NULL)
		return (true);
	current = a->top;
	while (current && current->next)
	{
		if (current->value < current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_b_rev_sorted(t_stack *a, t_stack *b)
{
	t_list	*current;

	(void)a;
	if (b == NULL || b->top == NULL)
		return (true);
	current = b->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
