/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:26:09 by 20tyamato         #+#    #+#             */
/*   Updated: 2024/06/11 13:29:48 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_str(char *str, int *action, int *error)
{
	size_t	i;

	(void)*action;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else
		{
			*error = 1;
			i++;
		}
	}
	return ;
}

char	**duplicate_2d_array(char **argv)
{
	int		i;
	int		j;
	char	**duplicate;

	i = 0;
	while (argv[i] != NULL)
		i++;
	duplicate = (char **)malloc(sizeof(char *) * (i + 1));
	if (duplicate == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		duplicate[j] = ft_strdup(argv[j]);
		if (duplicate[j] == NULL)
		{
			while (j-- > 0)
				free(duplicate[j]);
			free(duplicate);
			return (NULL);
		}
		j++;
	}
	duplicate[i] = NULL;
	return (duplicate);
}

int	ft_2d_array_len(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

void	ft_free_2d_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
