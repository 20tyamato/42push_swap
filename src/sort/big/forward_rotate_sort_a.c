#include "push_swap.h"

int	get_max_num_in_stack(t_stack *stack);
int	get_position_from_top(t_stack *a, int value);

void	forward_rotate_sort_a(t_stack *a, t_stack *b)
{
	int	max_position;
	int	stack_size;

	max_position = get_position_from_top(a, get_max_num_in_stack(a)) + 1;
	stack_size = a->size;
	if (is_sorted(a))
		return ;
	if (max_position < stack_size / 2)
	{
		while (max_position--)
			forward_rotate_a(a, b);
	}
	else
	{
		max_position = stack_size - max_position;
		while (max_position--)
			reverse_rotate_a(a, b);
	}
}
