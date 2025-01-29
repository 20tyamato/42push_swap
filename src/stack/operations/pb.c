/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:46 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:47 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top != NULL)
	{
		push(stack_b, pop(stack_a));
		ft_putstr_fd("pb\n", 1);
	}
	else
		return ;
}
