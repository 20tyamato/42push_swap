#include "push_swap.h"

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, stack_b);
	swap_b(stack_a, stack_b);
	ft_putstr_fd("ss\n", 1);
}
