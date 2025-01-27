#include "push_swap.h"

int get_top_element_of_stack(t_stack *stack);
int get_bottom_element_of_stack(t_stack *stack);
int	get_max_num_in_stack(t_stack *stack);
int	get_min_num_in_stack(t_stack *stack);
int get_second_max_num_in_stack(t_stack *stack);
int get_second_min_num_in_stack(t_stack *stack);
int	get_middle_num_in_stack(t_stack *stack);
int get_position_of_num(t_stack *a, int value);

void rev_sort_b(t_stack *a, t_stack *b)
{
	int min_position;
	int stack_size;

	min_position = get_position_of_num(b, get_min_num_in_stack(b)) + 1;
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
