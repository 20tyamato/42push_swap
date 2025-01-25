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

// 6以下
// void	sort_small_stack(t_stack *a, t_stack *b);

// void	sort_small_stack(t_stack *a, t_stack *b)
// {
// 	if (a->size == 2)
// 		sort_stack_of_two(a, b);
// 	else if (a->size == 3)
// 		sort_stack_of_three(a, b);
// 	else if (a->size == 4)
// 	{
// 		push_b(a, b);
// 		sort_small_stack(a, b);
// 		push_a(a, b);
// 	}
// 	else if (a->size == 5)
// 	{
// 		push_b(a, b);
// 		push_b(a, b);
// 		sort_small_stack(a, b);
// 		push_a(a, b);
// 		push_a(a, b);
// 	}
// 	else
// 	{
// 		push_b(a, b);
// 		sort_small_stack(a, b);
// 		push_a(a, b);
// 	}
// }
