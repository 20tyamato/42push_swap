#include "push_swap.h"

void	sort_small_stack(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *a, t_stack *b);

void	sort_big_stack_test(t_stack *a, t_stack *b);

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	print_stack_side_by_side(a, b);
	if (size <= SMALL_STACK_THRESHOLD)
		sort_small_stack(a, b);
	else
		sort_big_stack(a, b);
}
