#include "push_swap.h"

void	rev_sort_stack_of_two(t_stack *a, t_stack *b)
{
	if (b->top->value < b->top->next->value)
		swap_b(a, b);
}

void	rev_sort_stack_of_three(t_stack *a, t_stack *b)
{
	if (b->top->next->value > b->top->value && \
				b->top->value > b->top->next->next->value)
		swap_b(a, b);
	else if (b->top->next->next->value > b->top->next->value && \
				b->top->next->value > b->top->value)
	{
		swap_b(a, b);
		reverse_rotate_b(a, b);
	}
	else if (b->top->next->value > b->top->next->next->value && \
				b->top->next->next->value > b->top->value)
		forward_rotate_a(a, b);
	else if (b->top->value > b->top->next->next->value && \
				b->top->next->next->value > b->top->next->value)
	{
		swap_b(a, b);
		forward_rotate_b(a, b);
	}
	else if (b->top->next->next->value > b->top->value && \
				b->top->value > b->top->next->value)
		reverse_rotate_b(a, b);
}

void	rev_sort_small_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = b->size;
	if (size == 2)
		rev_sort_stack_of_two(a, b);
	else if (size == 3)
		rev_sort_stack_of_three(a, b);
}
