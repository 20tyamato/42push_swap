#include "push_swap.h"

void	push_first_element_to_a(t_stack *a, t_stack *b);
void	push_second_element_to_a(t_stack *a, t_stack *b);
void	sort_stack_of_three(t_stack *a, t_stack *b);
void	sort_stack_of_four(t_stack *a, t_stack *b);

void	sort_stack_of_five(t_stack *a, t_stack *b)
{
	push_b(a, b);
	// push_b(a, b);
	// sort_stack_of_three(a, b);
	sort_stack_of_four(a, b);
	push_first_element_to_a(a, b);
	// push_second_element_to_a(a, b);
}
