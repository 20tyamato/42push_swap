/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:08:13 by 20tyamato         #+#    #+#             */
/*   Updated: 2023/12/10 03:49:10 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*head;
	char	*tail;

	if (s1 == NULL || set == NULL)
		return (NULL);
	head = (char *)s1;
	tail = (char *)s1 + ft_strlen(s1) - 1;
	while (*head && ft_strchr(set, *head))
		head++;
	while (tail > head && ft_strchr(set, *tail))
		tail--;
	return (ft_substr(head, 0, tail - head + 1));
}
