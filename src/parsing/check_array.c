#include "push_swap.h"

int	get_array_size(long long *array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

bool	is_within_range(long long *array, int size,
						long long min, long long max)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] < min || array[i] > max)
			return (false);
		i++;
	}
	return (true);
}

bool	has_duplicates(long long *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid_array(long long *array)
{
	int	size;

	size = get_array_size(array);
	if (!is_within_range(array, size, INT_MIN, INT_MAX))
		return (false);
	if (has_duplicates(array, size))
		return (false);
	return (true);
}
