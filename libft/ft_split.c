/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:12:10 by 20tyamato         #+#    #+#             */
/*   Updated: 2023/12/11 14:05:13 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			++i;
	}
	return (count);
}

static void	*ft_free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char	*ft_strndup(const char *s, int n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (result == NULL)
		return (NULL);
	result[n] = '\0';
	while (n--)
		result[n] = s[n];
	return (result);
}

static void	ft_init(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (s == NULL || result == NULL)
		return (NULL);
	ft_init(&i, &j);
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i] == '\0')
			break ;
		k = 0;
		while (s[i + k] && s[i + k] != c)
			++k;
		result[j++] = ft_strndup(s + i, k);
		if ((result[j - 1]) == NULL)
			return (ft_free_split(result));
		i += k;
	}
	result[j] = NULL;
	return (result);
}
