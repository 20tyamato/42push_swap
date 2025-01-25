#include "push_swap.h"

void	swap_b(t_stack *stack_a, t_stack *stack_b)
{
	int	first_element;
	int	second_element;

	(void)stack_a;
	first_element = pop(stack_b);
	if (first_element == -1)
		return ;
	second_element = pop(stack_b);
	if (second_element == -1)
	{
		push(stack_b, first_element);
		return ;
	}
	push(stack_b, first_element);
	push(stack_b, second_element);
	ft_putstr_fd("sb\n", 1);
}
