/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_utils_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:26:09 by 20tyamato         #+#    #+#             */
/*   Updated: 2024/06/10 21:45:41 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*to_array(char **s, int size)
{
	int	*array;
	int	i;

	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi_long(s[i]);
		i++;
	}
	return (array);
}

int	*to_array_ext(char **s, int size)
{
	int	*array;
	int	i;

	array = (int *)malloc((size - 1) * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		array[i] = ft_atoi_long(s[i + 1]);
		i++;
	}
	return (array);
}

int	is_array_sorted(int *array, int size)
{
	int	i;

	if (array == NULL)
		return (1);
	else if (array != NULL && size == 1)
		return (1);
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_array_duplicate(int *array, int size)
{
	int	i;

	i = 0;
	ft_quick_sort(array, 0, size - 1);
	while (i < size - 1)
	{
		if (array[i] == array[i + 1])
			return (1);
		i++;
	}
	return (0);
}
