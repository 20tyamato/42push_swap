/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:33:53 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/30 12:38:35 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
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
