/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:35:05 by 20tyamato         #+#    #+#             */
/*   Updated: 2023/12/10 03:10:11 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (*str == (char)c)
		return ((char *)str);
	while (*str)
	{
		str++;
		if (*str == (char)c)
			return ((char *)str);
	}
	return (NULL);
}
