/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:29 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:29 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size <= SMALL_STACK_THRESHOLD)
		sort_small_stack(a, b);
	else
		sort_big_stack(a, b);
}
