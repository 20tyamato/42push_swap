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

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, stack_b);
	swap_b(stack_a, stack_b);
	ft_putstr_fd("ss\n", 1);
}
