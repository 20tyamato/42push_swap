/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:02 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:43:03 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
