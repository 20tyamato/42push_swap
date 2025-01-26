#include "push_swap.h"

void	sort_stack_of_two(t_stack *a, t_stack *b);
void	sort_stack_of_three(t_stack *a, t_stack *b);
// void	sort_small_stack(t_stack *a, t_stack *b);
// void	sort_big_stack(t_stack *a, t_stack *b);

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort_stack_of_two(a, b);
	else if (size == 3)
		sort_stack_of_three(a, b);
	// else if (size <= 6)
	// 	sort_small_stack(a, b);
	// else
	// 	sort_big_stack(a, b);
}
