/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:32 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:32 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_list	*current;

	if (stack == NULL || stack->top == NULL)
		return (true);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_rev_sorted(t_stack *stack)
{
	t_list	*current;

	if (stack == NULL || stack->top == NULL)
		return (true);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value < current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
