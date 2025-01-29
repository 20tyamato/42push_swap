/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:58 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:58 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*last;
	t_list	*tmp;

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

void	fake_reverse_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*last;
	t_list	*tmp;

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
}
