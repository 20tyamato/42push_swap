/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:47:14 by 20tyamato         #+#    #+#             */
/*   Updated: 2023/12/10 02:47:27 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;

	if (elementSize != 0 && elementCount > SIZE_MAX / elementSize)
		return (NULL);
	ptr = malloc(elementCount * elementSize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, elementCount * elementSize);
	return (ptr);
}
