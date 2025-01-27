#include "push_swap.h"

int get_top_element_of_stack(t_stack *stack);
int get_bottom_element_of_stack(t_stack *stack);
int	get_max_num_in_stack(t_stack *stack);
int	get_min_num_in_stack(t_stack *stack);
int get_second_max_num_in_stack(t_stack *stack);
int get_second_min_num_in_stack(t_stack *stack);
int	get_middle_num_in_stack(t_stack *stack);
int get_position_of_num(t_stack *a, int value);

void	sort_a(t_stack *a, t_stack *b)
{
	int max_position;
	int stack_size;

	max_position = get_position_of_num(a, get_max_num_in_stack(a));
	stack_size = a->size;
	if (is_sorted(a))
		return ;
	if (max_position < stack_size / 2)
	{
		while (a->top->value != get_max_num_in_stack(a))
			forward_rotate_a(a, b);
	}
	else
	{
		while (a->top->value != get_max_num_in_stack(a))
			reverse_rotate_a(a, b);
	}
}
