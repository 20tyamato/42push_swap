#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
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
	char	*max;

	max = "18446744073709551616";
	while (ft_isspace(*str))
		str++;
	if (ft_strcmp(str, max) == 0)
		return (-1);
	if (sign > 0 && res >= LONG_MAX)
		return (-1);
	else if (sign < 0 && res > LONG_MAX)
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	char				*original_str;

	res = 0;
	sign = 1;
	original_str = (char *)str;
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
	if (ft_isvalid(res, sign, original_str) == -1
		|| ft_isvalid(res, sign, original_str) == 0)
		return (ft_isvalid(res, sign, original_str));
	return (res * sign);
}
