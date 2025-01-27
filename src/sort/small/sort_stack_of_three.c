#include "push_swap.h"

void	sort_stack_of_three(t_stack *a, t_stack *b)
{
	if (a->top->next->value < a->top->value && \
				a->top->value < a->top->next->next->value)
		swap_a(a, b);
	else if (a->top->next->next->value < a->top->next->value && \
				a->top->next->value < a->top->value)
	{
		swap_a(a, b);
		reverse_rotate_a(a, b);
	}
	else if (a->top->next->value < a->top->next->next->value && \
				a->top->next->next->value < a->top->value)
		forward_rotate_a(a, b);
	else if (a->top->value < a->top->next->next->value && \
				a->top->next->next->value < a->top->next->value)
	{
		swap_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (a->top->next->next->value < a->top->value && \
				a->top->value < a->top->next->value)
		reverse_rotate_a(a, b);
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
