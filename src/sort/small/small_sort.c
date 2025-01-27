#include "push_swap.h"

void	sort_stack_of_two(t_stack *a, t_stack *b);
void	sort_stack_of_three(t_stack *a, t_stack *b);
void	sort_stack_of_four(t_stack *a, t_stack *b);
void	sort_stack_of_five(t_stack *a, t_stack *b);

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
