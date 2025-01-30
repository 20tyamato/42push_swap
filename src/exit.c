/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:37:56 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/30 12:37:57 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

int	clean_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	return (EXIT_SUCCESS);
}
