#include "push_swap.h"

long long	*args_to_array(char **str, int size)
{
	long long	*array;
	int	i;

	array = (long long *)malloc(size * sizeof(long long));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = atoll(str[i]);
		i++;
	}
	return (array);
}

int get_string_array_size(char **str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void free_string_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

long long	*string_to_array(char **str)
{
	long long	*array;
	char	**split;
	int	i;
	int size;

	split = ft_split(str[1], ' ');
	if (split == NULL)
		return (NULL);
	size = get_string_array_size(split);
	array = (long long *)malloc(size * sizeof(long long));
	if (array == NULL)
	{
		free_string_array(split);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		array[i] = atoll(split[i]);
		i++;
	}
	free_string_array(split);
	return (array);
}
