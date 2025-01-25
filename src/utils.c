#include "push_swap.h"

int	is_bigger_than_int(char *s)
{
	long	num;

	if (ft_strlen(s) >= 18)
		return (1);
	else
	{
		if (*s == '-')
		{
			num = ft_atoi_long(s);
			if (num < INT_MIN || num == 0)
				return (1);
		}
		else
		{
			num = ft_atoi_long(s);
			if (INT_MAX < num)
				return (1);
		}
	}
	return (0);
}

int	ft_isdigit_ext(int c)
{
	if (c == '\n')
		return (1);
	return (c >= '0' && c <= '9');
}

int	is_all_digit(char *s)
{
	int	minus_count;

	minus_count = 0;
	if (*s != '-' && !ft_isdigit_ext(*s))
		return (0);
	s++;
	while (*s)
	{
		if (*s == '-')
			minus_count++;
		if (!ft_isdigit_ext(*s))
			return (0);
		s++;
	}
	if (minus_count > 1)
		return (0);
	return (1);
}
