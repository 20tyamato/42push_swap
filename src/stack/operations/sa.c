#include "push_swap.h"

void	swap_a(t_stack *stack_a, t_stack *stack_b)
{
	int	first_element;
	int	second_element;

	(void)stack_b;
	first_element = pop(stack_a);
	if (first_element == -1)
		return ;
	second_element = pop(stack_a);
	if (second_element == -1)
	{
		push(stack_a, first_element);
		return ;
	}
	push(stack_a, first_element);
	push(stack_a, second_element);
	ft_putstr_fd("sa\n", 1);
}
