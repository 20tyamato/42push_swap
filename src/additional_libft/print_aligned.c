/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aligned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:41:51 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/29 12:41:52 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_spaces(int count)
{
	while (count-- > 0)
		write(1, " ", 1);
}

void	print_aligned_int(int n, int width, int is_left)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	if (!s)
		return ;
	len = (int)ft_strlen(s);
	if (is_left)
	{
		write(1, s, len);
		if (len < width)
			put_spaces(width - len);
	}
	else
	{
		if (len < width)
			put_spaces(width - len);
		write(1, s, len);
	}
	free(s);
}

void	print_aligned_str(const char *str, int width, int is_left)
{
	int	len;

	len = (int)ft_strlen(str);
	if (is_left)
	{
		write(1, str, len);
		if (len < width)
			put_spaces(width - len);
	}
	else
	{
		if (len < width)
			put_spaces(width - len);
		write(1, str, len);
	}
}
