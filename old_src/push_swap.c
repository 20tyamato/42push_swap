#include "push_swap.h"

void	push_swap_forward(t_stack *stack_a, t_stack *stack_b, int place)
{
	size_t	num;
	size_t	stack_init_size;

	num = 0;
	stack_init_size = stack_size(stack_a);
	while (num < stack_init_size)
	{
		if (((stack_a->top->data >> place) & 1) == 0)
			push_b(stack_a, stack_b);
		else
			forward_rotate_a(stack_a, stack_b);
		num++;
	}
}

void	push_swap_back(t_stack *stack_a, t_stack *stack_b, int place)
{
	size_t	num;
	size_t	stack_init_size;

	num = 0;
	stack_init_size = stack_size(stack_b);
	place++;
	while (num < stack_init_size)
	{
		if (((stack_b->top->data >> place) & 1) == 0)
			forward_rotate_b(stack_a, stack_b);
		else
			push_a(stack_a, stack_b);
		num++;
	}
}

void	return_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_stack_empty(stack_b))
		push_a(stack_a, stack_b);
}

void	fill_stack_a(t_stack *stack_a, int size, int *array)
{
	int	i;

	i = size;
	while (i > 0)
	{
		push(stack_a, array[i - 1]);
		i--;
	}
	return ;
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	place;

	place = 0;
	while (place < 32 && !is_stack_sorted(stack_a))
	{
		push_swap_forward(stack_a, stack_b, place);
		if (is_stack_sorted_rev(stack_b) && is_stack_sorted(stack_a))
			return_stack_a(stack_a, stack_b);
		push_swap_back(stack_a, stack_b, place);
		if (is_stack_sorted_rev(stack_b) && is_stack_sorted(stack_a))
			return_stack_a(stack_a, stack_b);
		place++;
	}
}
