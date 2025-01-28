#include "push_swap.h"

void	push_first_element_to_a(t_stack *a, t_stack *b);
void	push_second_element_to_a(t_stack *a, t_stack *b);

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

void	sort_stack_of_four(t_stack *a, t_stack *b)
{
	push_b(a, b);
	sort_stack_of_three(a, b);
	push_first_element_to_a(a, b);
}


void	sort_stack_of_five(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	sort_stack_of_three(a, b);
	push_first_element_to_a(a, b);
	push_second_element_to_a(a, b);
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort_stack_of_two(a, b);
	else if (size == 3)
		sort_stack_of_three(a, b);
	else if (size == 4)
		sort_stack_of_four(a, b);
	else
		sort_stack_of_five(a, b);
}
