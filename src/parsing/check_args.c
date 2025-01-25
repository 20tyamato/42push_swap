#include "push_swap.h"

bool is_valid_string(const char *str)
{
    while (*str)
    {
        if (!(*str == ' ' || *str == '\t' || *str == '-' || (*str >= '0' && *str <= '9')))
            return (false);
        str++;
    }
    return (true);
}

bool is_valid_args(int argc, char **argv)
{
	if (ft_strncmp(argv[0], "./push_swap", ft_strlen("./push_swap")) != 0)
		return (false);
	for (int i = 1; i < argc; i++)
	{
		if (!is_valid_string(argv[i]))
			return (false);
	}
	return (true);
}
