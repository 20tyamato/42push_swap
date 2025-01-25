#include "push_swap.h"

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
