#include "push_swap.h"

void	sort_stack_of_two(t_stack *a, t_stack *b)
{
	if (a->top->value > a->top->next->value)
		swap_a(a, b);
}

void	rev_sort_stack_of_two(t_stack *a, t_stack *b)
{
	if (b->top->value < b->top->next->value)
		swap_b(a, b);
}
