#include "push_swap.h"

void	push_first_element_to_a(t_stack *a, t_stack *b);
void	sort_stack_of_three(t_stack *a, t_stack *b);

void	sort_stack_of_four(t_stack *a, t_stack *b)
{
	push_b(a, b);
	sort_stack_of_three(a, b);
	push_first_element_to_a(a, b);
}
