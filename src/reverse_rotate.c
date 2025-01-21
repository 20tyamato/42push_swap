/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:56:46 by 20tyamato         #+#    #+#             */
/*   Updated: 2024/04/10 00:07:56 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*last;
	t_node	*tmp;

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

void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*last;
	t_node	*tmp;

	(void)stack_a;
	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	last = stack_b->top;
	tmp = NULL;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	if (tmp != NULL)
		tmp->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a, stack_b);
	reverse_rotate_b(stack_a, stack_b);
	ft_putstr_fd("rrr\n", 1);
}
