#include "push_swap.h"

int	get_array_size(long long *array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}


bool	is_within_range(long long *array, int size, long long min, long long max)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] < min || array[i] > max)
			return (false);
	}
	return (true);
}

bool	has_duplicates(long long *array, int size)
{
	int	i, j;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
				return (true);
		}
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
