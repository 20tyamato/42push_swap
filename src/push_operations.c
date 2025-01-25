#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top != NULL)
	{
		push(stack_a, pop(stack_b));
		ft_putstr_fd("pa\n", 1);
	}
	else
		return ;
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top != NULL)
	{
		push(stack_b, pop(stack_a));
		ft_putstr_fd("pb\n", 1);
	}
	else
		return ;
}
