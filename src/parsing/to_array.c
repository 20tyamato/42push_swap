#include "push_swap.h"

t_array	*args_to_array(char **str, int size)
{
	t_array	*arr;
	int		i;

	arr = (t_array *)malloc(sizeof(t_array));
	if (!arr)
		return (NULL);
	arr->array = (long long *)malloc(size * sizeof(long long));
	if (!arr->array)
	{
		free(arr);
		return (NULL);
	}
	arr->size = size;
	i = 0;
	while (i < size)
	{
		arr->array[i] = atoll(str[i]);
		i++;
	}
	return (arr);
}

static t_array	*create_array_from_split(char **split)
{
	t_array	*arr;
	int		i;

	arr = (t_array *)malloc(sizeof(t_array));
	if (!arr)
		return (NULL);
	arr->size = get_string_array_size(split);
	arr->array = (long long *)malloc(arr->size * sizeof(long long));
	if (!arr->array)
	{
		free(arr);
		return (NULL);
	}
	i = 0;
	while (i < arr->size)
	{
		arr->array[i] = atoll(split[i]);
		i++;
	}
	return (arr);
}

t_array	*string_to_array(char **str)
{
	t_array	*arr;
	char	**split;

	split = ft_split(str[0], ' ');
	if (!split)
		return (NULL);
	arr = create_array_from_split(split);
	if (!arr)
	{
		free_string_array(split);
		return (NULL);
	}
	free_string_array(split);
	return (arr);
}
