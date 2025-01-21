/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:57:21 by 20tyamato         #+#    #+#             */
/*   Updated: 2024/04/10 00:07:30 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	forward_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*last;

	(void)stack_b;
	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	last = stack_a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	forward_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*last;

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

void	forward_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	forward_rotate_a(stack_a, stack_b);
	forward_rotate_b(stack_a, stack_b);
	ft_putstr_fd("rr\n", 1);
}
