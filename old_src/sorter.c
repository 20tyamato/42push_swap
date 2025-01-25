#include "push_swap.h"

void	sort_three(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (argc == 2 && stack_a->top->data == 1 && stack_a->top->next->data == 0)
		swap_a(stack_a, stack_b);
	else if (stack_a->top->next->data < stack_a->top->data && \
				stack_a->top->data < stack_a->top->next->next->data)
		swap_a(stack_a, stack_b);
	else if (stack_a->top->next->next->data < stack_a->top->next->data && \
				stack_a->top->next->data < stack_a->top->data)
	{
		swap_a(stack_a, stack_b);
		reverse_rotate_a(stack_a, stack_b);
	}
	else if (stack_a->top->next->data < stack_a->top->next->next->data && \
				stack_a->top->next->next->data < stack_a->top->data)
		forward_rotate_a(stack_a, stack_b);
	else if (stack_a->top->data < stack_a->top->next->next->data && \
				stack_a->top->next->next->data < stack_a->top->next->data)
	{
		swap_a(stack_a, stack_b);
		forward_rotate_a(stack_a, stack_b);
	}
	else if (stack_a->top->next->next->data < stack_a->top->data && \
				stack_a->top->data < stack_a->top->next->data)
		reverse_rotate_a(stack_a, stack_b);
}

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		min_index;

	current = stack->top;
	min = current->data;
	min_index = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = 0;
		}
		current = current->next;
		min_index++;
	}
	return (min_index);
}

void	sort_six(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min;
	int		min_index;

	i = stack_size(stack_a);
	min = get_min(stack_a);
	min_index = get_min_index(stack_a);
	if (is_stack_sorted(stack_a))
		return ;
	while (i > 3)
	{
		if (stack_a->top->data == min)
		{
			push_b(stack_a, stack_b);
			min = get_min(stack_a);
			i--;
		}
		else if (min_index < (int)stack_size(stack_a) / 2 + 1)
			reverse_rotate_a(stack_a, stack_b);
		else
			forward_rotate_a(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b, 3);
	while (i++ <= (int)stack_size(stack_a))
		push_a(stack_a, stack_b);
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (argc < 4)
		sort_three(stack_a, stack_b, argc);
	else if (argc < 7)
		sort_six(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b);
}
