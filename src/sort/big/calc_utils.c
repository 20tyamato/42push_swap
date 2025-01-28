#include "push_swap.h"

static bool	is_out_of_range(t_stack *stack, int value)
{
	return (value > get_max_num_in_stack(stack)
		|| value < get_min_num_in_stack(stack));
}

static bool	is_between_borders(t_stack *stack, int value)
{
	int	bottom;
	int	top;

	bottom = get_bottom_element_of_stack(stack);
	top = get_top_element_of_stack(stack);
	return (!(bottom < value && value < top)
		|| (bottom > value && value > top));
}

static bool	is_bottom_min_or_top_max(t_stack *stack)
{
	return (
		get_bottom_element_of_stack(stack) == get_min_num_in_stack(stack)
		|| get_top_element_of_stack(stack) == get_max_num_in_stack(stack)
	);
}

int	count_steps_using_rb(t_stack *a, t_stack *b, int value)
{
	int		count;
	t_stack	*tmp_b;

	(void)a;
	count = 0;
	tmp_b = copy_stack(b);
	if (is_bottom_min_or_top_max(tmp_b))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
	}
	while (is_between_borders(tmp_b, value))
	{
		count++;
		fake_reverse_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return (-1);
		}
	}
	free_stack(tmp_b);
	return (count);
}

int	count_steps_using_rrb(t_stack *a, t_stack *b, int value)
{
	int		count;
	t_stack	*tmp_b;

	(void)a;
	count = 0;
	tmp_b = copy_stack(b);
	if (is_bottom_min_or_top_max(tmp_b))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
	}
	while (is_between_borders(tmp_b, value))
	{
		count++;
		fake_forward_rotate_b(a, tmp_b);
		if (count > b->size)
		{
			free_stack(tmp_b);
			return (-1);
		}
	}
	free_stack(tmp_b);
	return (count);
}
