/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:00 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/30 12:03:03 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	fake_reverse_rotate_a(stack_a, stack_b);
	fake_reverse_rotate_b(stack_a, stack_b);
	ft_putstr_fd("rrr\n", 1);
}

void	fake_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	fake_reverse_rotate_a(stack_a, stack_b);
	fake_reverse_rotate_b(stack_a, stack_b);
}
