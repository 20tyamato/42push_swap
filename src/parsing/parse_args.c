#include "push_swap.h"

bool		is_valid_args(int argc, char **argv);
bool		is_valid_array(long long *array);

int			get_array_size(long long *array);

long long	*args_to_array(char **str, int size);
long long	*string_to_array(char **str);

void	store_stack(t_stack *a, t_stack *b, long long *array)
{
	int	i;
	int	size;

	(void)b;
	i = 0;
	size = get_array_size(array);
	while (i < size)
	{
		push(a, (int)array[i]);
		i++;
	}
}

bool	parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	long long	*array;

	if (!is_valid_args(argc, argv))
		return (false);
	if (argc == 2)
		array = string_to_array(&argv[1]);
	else
		array = args_to_array(argv + 1, argc - 1);
	if (array == NULL)
		return (false);
	if (!is_valid_array(array))
	{
		free(array);
		return (false);
	}
	store_stack(a, b, array);
	free(array);
	return (true);
}
