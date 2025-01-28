#include "push_swap.h"

void	rev_rotate_sort_b(t_stack *a, t_stack *b)
{
	int	min_position;
	int	stack_size;

	min_position = get_position_from_top(b, get_min_num_in_stack(b)) + 1;
	stack_size = b->size;
	if (is_rev_sorted(b))
		return ;
	if (min_position < stack_size / 2)
	{
		while (min_position--)
			forward_rotate_b(a, b);
	}
	else
	{
		min_position = stack_size - min_position;
		while (min_position--)
			reverse_rotate_b(a, b);
	}
}
