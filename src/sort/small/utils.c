#include "push_swap.h"

int	get_top_element_of_stack(t_stack *stack);
int	get_bottom_element_of_stack(t_stack *stack);
int	get_max_num_in_stack(t_stack *stack);
int	get_min_num_in_stack(t_stack *stack);
int	get_second_max_num_in_stack(t_stack *stack);
int	get_second_min_num_in_stack(t_stack *stack);
int	get_middle_num_in_stack(t_stack *stack);

int	get_middle_num_in_stack(t_stack *stack)
{
	int		size;
	t_list	*current;
	int		i;

	size = stack->size;
	current = stack->top;
	if (size % 2 == 0)
		i = 0;
	else
		i = 1;
	while (i != size / 2)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

void	push_first_element_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	mid;
	int	min;
	int	first_in_number;
	int	second_in_number;

	max = get_max_num_in_stack(a);
	mid = get_second_max_num_in_stack(a);
	min = get_min_num_in_stack(a);
	first_in_number = get_top_element_of_stack(b);
	second_in_number = get_bottom_element_of_stack(b);
	if (max < first_in_number)
	{
		push_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (min > first_in_number)
		push_a(a, b);
	else if (mid < first_in_number)
	{
		reverse_rotate_a(a, b);
		push_a(a, b);
		if (second_in_number < first_in_number && second_in_number > mid)
		{
			push_a(a, b);
			forward_rotate_a(a, b);
		}
		forward_rotate_a(a, b);
		forward_rotate_a(a, b);
	}
	else
	{
		forward_rotate_a(a, b);
		push_a(a, b);
		reverse_rotate_a(a, b);
	}
	return ;
}

void	push_second_element_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	second_max;
	int	second_min;
	int	min;
	int	in_number;

	max = get_max_num_in_stack(a);
	second_max = get_second_max_num_in_stack(a);
	second_min = get_second_min_num_in_stack(a);
	min = get_min_num_in_stack(a);
	in_number = get_top_element_of_stack(b);
	if (max < in_number)
	{
		push_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (min > in_number)
		push_a(a, b);
	else if (second_max < in_number)
	{
		reverse_rotate_a(a, b);
		push_a(a, b);
		forward_rotate_a(a, b);
		forward_rotate_a(a, b);
	}
	else if (second_min > in_number)
	{
		forward_rotate_a(a, b);
		push_a(a, b);
		reverse_rotate_a(a, b);
	}
	else
	{
		forward_rotate_a(a, b);
		forward_rotate_a(a, b);
		push_a(a, b);
		reverse_rotate_a(a, b);
		reverse_rotate_a(a, b);
	}
	return ;
}
