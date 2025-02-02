/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:48 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:49 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forward_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	t_list	*last;

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

void	fake_forward_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	t_list	*last;

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
}
