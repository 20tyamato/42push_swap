#include "push_swap.h"

void	forward_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	t_list	*last;

	(void)stack_a;
	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	last = stack_b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd("rb\n", 1);
}
