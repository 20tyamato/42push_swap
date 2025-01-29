/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:11 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:43:11 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parse_args(int argc, char **argv, t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	errno = 0;
	if (argc < 2 || argc > INT_MAX)
		return (EXIT_FAILURE);
	a = create_stack();
	b = create_stack();
	if (!parse_args(argc, argv, a, b))
		return (error_exit(a, b));
	if (is_sorted(a))
		return (clean_exit(a, b));
	push_swap(a, b);
	return (clean_exit(a, b));
}
