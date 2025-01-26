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

int	get_string_array_size(char **str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	free_string_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_array	*string_to_array(char **str)
{
	t_array	*arr;
	char	**split;
	int		i;

	split = ft_split(str[0], ' ');
	if (!split)
		return (NULL);
	arr = (t_array *)malloc(sizeof(t_array));
	if (!arr)
	{
		free_string_array(split);
		return (NULL);
	}
	arr->size = get_string_array_size(split);
	arr->array = (long long *)malloc(arr->size * sizeof(long long));
	if (!arr->array)
	{
		free(arr);
		free_string_array(split);
		return (NULL);
	}
	i = 0;
	while (i < arr->size)
	{
		arr->array[i] = atoll(split[i]);
		i++;
	}
	free_string_array(split);
	return (arr);
}
