#include "push_swap.h"

bool	is_valid_string(const char *str)
{
	while (*str)
	{
		if (!(*str == ' '
				|| *str == '\t'
				|| *str == '-'
				|| (*str >= '0' && *str <= '9')))
			return (false);
		str++;
	}
	return (true);
}

bool	is_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_string(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
