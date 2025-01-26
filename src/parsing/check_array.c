#include "push_swap.h"

bool	is_within_range(t_array *arr, long long min, long long max)
{
	int	i;

	i = 0;
	while (i < arr->size)
	{
		if (arr->array[i] < min || arr->array[i] > max)
			return (false);
		i++;
	}
	return (true);
}

bool	has_duplicates(t_array *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr->size)
	{
		j = i + 1;
		while (j < arr->size)
		{
			if (arr->array[i] == arr->array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid_array(t_array *arr)
{
	if (!is_within_range(arr, INT_MIN, INT_MAX))
		return (false);
	if (has_duplicates(arr))
		return (false);
	return (true);
}
