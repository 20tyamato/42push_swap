#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*last;
	t_list	*tmp;

	(void)stack_b;
	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	last = stack_a->top;
	tmp = NULL;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	if (tmp != NULL)
		tmp->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
	ft_putstr_fd("rra\n", 1);
}
