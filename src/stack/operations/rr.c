/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:53 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/30 12:02:47 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forward_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	fake_forward_rotate_a(stack_a, stack_b);
	fake_forward_rotate_b(stack_a, stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	fake_forward_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	fake_forward_rotate_a(stack_a, stack_b);
	fake_forward_rotate_b(stack_a, stack_b);
}
