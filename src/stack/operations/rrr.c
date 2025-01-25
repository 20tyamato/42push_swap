#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a, stack_b);
	reverse_rotate_b(stack_a, stack_b);
	ft_putstr_fd("rrr\n", 1);
}
