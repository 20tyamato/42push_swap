/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:00 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:42:00 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_args(int argc, char **argv);
bool	is_valid_array(t_array *arr);

t_array	*string_to_array(char **str);
t_array	*args_to_array(char **str, int size);

static void	store_stack(t_stack *a, t_stack *b, t_array *arr)
{
	int	i;

	(void)b;
	i = arr->size - 1;
	while (i >= 0)
	{
		push(a, (int)arr->array[i]);
		i--;
	}
}

bool	parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	t_array	*arr;

	if (!is_valid_args(argc, argv))
		return (false);
	if (argc == 2)
		arr = string_to_array(&argv[1]);
	else
		arr = args_to_array(argv + 1, argc - 1);
	if (arr == NULL)
		return (false);
	if (!is_valid_array(arr))
	{
		free(arr->array);
		free(arr);
		return (false);
	}
	store_stack(a, b, arr);
	free(arr->array);
	free(arr);
	return (true);
}
