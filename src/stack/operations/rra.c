/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:55 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:56 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	fake_reverse_rotate_a(t_stack *stack_a, t_stack *stack_b)
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
}
