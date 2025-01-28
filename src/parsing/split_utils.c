#include "push_swap.h"

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
