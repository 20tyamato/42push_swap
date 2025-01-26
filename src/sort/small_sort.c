#include "push_swap.h"

void	sort_stack_of_two(t_stack *a, t_stack *b)
{
	if (a->top->value > a->top->next->value)
		swap_a(a, b);
}

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

// TODO: sizeが1の場合は？
void	sort_small_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort_stack_of_two(a, b);
	else if (size == 3)
		sort_stack_of_three(a, b);
}

// 6以下
// void	sort_small_stack(t_stack *a, t_stack *b);
