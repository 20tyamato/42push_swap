#include "push_swap.h"

void	forward_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	forward_rotate_b(t_stack *stack_a, t_stack *stack_b);

void	forward_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	forward_rotate_a(stack_a, stack_b);
	forward_rotate_b(stack_a, stack_b);
	ft_putstr_fd("rr\n", 1);
}
