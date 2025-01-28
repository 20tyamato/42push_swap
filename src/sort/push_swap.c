#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size <= SMALL_STACK_THRESHOLD)
		sort_small_stack(a, b);
	else
		sort_big_stack(a, b);
}
