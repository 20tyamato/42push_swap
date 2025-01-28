#include "push_swap.h"

int		get_string_array_size(char **str);
void	free_string_array(char **str);

bool	is_valid_string(const char *str)
{
	while (*str)
	{
		if (!(*str == ' '
				|| *str == '\t'
				|| *str == '-'
				|| (*str >= '0' && *str <= '9')))
			return (false);
		if (*str == '-' && (*(str + 1) == '\0' || !ft_isdigit(*(str + 1))))
			return (false);
		str++;
	}
	return (true);
}

bool	contains_multiple_numbers(const char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (!split)
		return (false);
	if (get_string_array_size(split) > 1)
	{
		free_string_array(split);
		return (true);
	}
	free_string_array(split);
	return (false);
}

bool	is_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_string(argv[i]))
			return (false);
		if (argc > 2 && contains_multiple_numbers(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
