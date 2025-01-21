/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:58:00 by 20tyamato         #+#    #+#             */
/*   Updated: 2024/06/10 20:01:17 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*duplicate_array(int *array, int size)
{
	int	*copy;
	int	i;

	copy = (int *)malloc((size + 1) * sizeof(int));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = array[i];
		i++;
	}
	return (copy);
}

int	*normalize_array(char **argv, int argc)
{
	int	*array;
	int	*copy;

	array = to_array(argv, argc);
	copy = duplicate_array(array, argc);
	if (!copy)
		return (NULL);
	ft_quick_sort(copy, 0, argc - 1);
	map_indexes(array, copy, argc);
	free(copy);
	return (array);
}

void	map_indexes(int *array, int *sorted_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == sorted_array[j])
			{
				array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
