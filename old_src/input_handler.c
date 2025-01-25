#include "push_swap.h"

void	valid_array(int *array, int size, int *error, int *action)
{
	if (is_array_duplicate(array, size))
		*error = 1;
	else
	{
		if (is_array_sorted(array, size))
			return ;
		else
			*action = 0;
	}
	return ;
}

void	check_input_validity(char **argv, int argc, int *error)
{
	int	i;

	if (ft_strncmp(argv[0], "./push_swap", ft_strlen("./push_swap")) == 0)
		i = 1;
	else
		i = 0;
	while (i < argc)
	{
		if (!is_all_digit(argv[i]) || is_bigger_than_int(argv[i]))
		{
			*error = 1;
			return ;
		}
		i++;
	}
}

void	valid_input(int argc, char **argv, int *action, int *error)
{
	int	*array;

	if (argc == 1)
		*action = 0;
	else if (ft_strncmp(argv[0], "./push_swap", ft_strlen("./push_swap")) == 0)
	{
		check_input_validity(argv, argc, error);
		if (*error == 0 && *action == 1)
		{
			array = to_array_ext(argv, argc);
			valid_array(array, argc - 1, error, action);
			free(array);
		}
	}
	else
	{
		check_input_validity(argv, argc, error);
		if (*error == 0 && *action == 1)
		{
			array = to_array(argv, argc);
			valid_array(array, argc, error, action);
			free(array);
		}
	}
}
