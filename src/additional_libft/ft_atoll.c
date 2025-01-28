#include "push_swap.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static long long	overflow_result(int sign)
{
	errno = ERANGE;
	if (sign > 0)
		return (LLONG_MAX);
	return (LLONG_MIN);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;
	int			digit;

	result = 0;
	sign = 1;
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit((unsigned char)*str))
	{
		digit = *str - '0';
		if (result > (LLONG_MAX - digit) / 10)
			return (overflow_result(sign));
		result = result * 10 + digit;
		str++;
	}
	if (sign < 0)
		result = -result;
	return (result);
}
