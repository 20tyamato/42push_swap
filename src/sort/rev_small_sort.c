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

// ここを実装する
// quick sortにする
// void	sort_stack_of_under_six(t_stack *a, t_stack *b)
// {
// 	int	min;
// 	int	max;

// 	min = get_min(a);
// 	max = get_max(a);
// 	if (a->top->value == min)
// 		push_b(a, b);
// 	else if (a->top->next->value == min)
// 	{
// 		push_b(a, b);
// 		swap_a(a, b);
// 	}
// 	else if (a->top->next->next->value == min)
// 	{
// 		reverse_rotate_a(a, b);
// 		push_b(a, b);
// 	}
// 	else
// 	{
// 		forward_rotate_a(a, b);
// 		push_b(a, b);
// 	}
// 	sort_stack_of_three(a, b);
// 	push_a(a, b);
// }

void	rev_sort_small_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = b->size;
	if (size == 2)
		rev_sort_stack_of_two(a, b);
	else if (size == 3)
		rev_sort_stack_of_three(a, b);
	// else
	// 	sort_stack_of_under_six(a, b);
}
