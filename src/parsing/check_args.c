/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:41:58 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/30 13:16:18 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_string(const char *str)
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

static bool has_only_spaces(const char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (false);
		str++;
	}
	return (true);
}

static bool	contains_multiple_numbers(const char *str)
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
		if (!*argv[i] || has_only_spaces(argv[i]))
			return (false);
		if (!is_valid_string(argv[i]))
			return (false);
		if (argc > 2 && contains_multiple_numbers(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
