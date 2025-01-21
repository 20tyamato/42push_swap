/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:49:16 by 20tyamato         #+#    #+#             */
/*   Updated: 2023/12/10 03:18:36 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dst;

	size = ft_strlen(src) + 1;
	dst = (char *)malloc(sizeof(char) * size);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}
