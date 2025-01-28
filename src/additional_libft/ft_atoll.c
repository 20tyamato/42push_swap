#include "push_swap.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	ft_isvalid(unsigned long long res, int sign, const char *str)
{
	char	*max_str;

	max_str = "9223372036854775808";
	while (ft_isspace(*str))
		str++;
	if (ft_strcmp(str, max_str) == 0)
		return (-1);
	if (sign > 0 && res > LLONG_MAX)
		return (-1);
	else if (sign < 0 && res > (unsigned long long)LLONG_MAX + 1ULL)
		return (0);
	return (1);
}

long long	ft_atoll(const char *str)
{
	unsigned long long	res;
	int					sign;
	const char			*original_str;
	int					check;

	res = 0;
	sign = 1;
	original_str = str;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	check = ft_isvalid(res, sign, original_str);
	if (check == -1 || check == 0)
		return (check);
	return ((long long)res * sign);
}
