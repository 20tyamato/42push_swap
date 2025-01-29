/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:07 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:43:07 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, stack_b);
	swap_b(stack_a, stack_b);
	ft_putstr_fd("ss\n", 1);
}
