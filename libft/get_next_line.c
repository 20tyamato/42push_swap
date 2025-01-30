/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 20tyamato <20tyamato@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:07:30 by 20tyamato         #+#    #+#             */
/*   Updated: 2025/01/30 12:07:41 by 20tyamato        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cleanup(char **input_str, char **save_str)
{
	if (input_str && *input_str)
	{
		free(*input_str);
		*input_str = NULL;
	}
	if (save_str && *save_str)
	{
		free(*save_str);
		*save_str = NULL;
	}
	return (NULL);
}

char	*process_input(char **input_str, char **save_str, ssize_t bytes_read)
{
	char	*newline_pos;
	char	*output_str;
	char	*new_save_str;

	newline_pos = ft_strchr(*input_str, '\n');
	if (newline_pos != NULL)
	{
		output_str = ft_substr(*input_str, 0, newline_pos - *input_str + 1);
		new_save_str = ft_strdup(newline_pos + 1);
		if (!output_str || !new_save_str)
			return (cleanup(input_str, save_str));
		*save_str = new_save_str;
	}
	else if (bytes_read == 0 && ft_strlen(*input_str) > 0)
	{
		output_str = ft_strdup(*input_str);
		if (!output_str)
			return (cleanup(input_str, save_str));
	}
	else
		return (NULL);
	free(*input_str);
	*input_str = NULL;
	return (output_str);
}

ssize_t	read_from_fd(int fd, char **input_str, char **save_str)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*tmp;

	if (*save_str)
		bytes_read = ft_strlen(*save_str);
	if (ft_strchr(*input_str, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		while (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			tmp = *input_str;
			*input_str = ft_strjoin(tmp, buffer);
			free(tmp);
			tmp = NULL;
			if (!*input_str)
				return (-1);
			if (ft_strchr(buffer, '\n'))
				break ;
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		}
	}
	return (bytes_read);
}

char	*finalize_line(char **input_str, char **save_str, ssize_t bytes_read)
{
	char	*processed_line;

	processed_line = process_input(input_str, save_str, bytes_read);
	if ((processed_line != NULL || ft_strlen(*input_str) == 0) \
												&& save_str == NULL)
	{
		cleanup(input_str, save_str);
		return (processed_line);
	}
	if (bytes_read == 0)
	{
		if (*input_str)
		{
			free(*input_str);
			*input_str = NULL;
		}
	}
	return (processed_line);
}

char	*get_next_line(int fd)
{
	static char	*save_str = NULL;
	char		*input_str;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save_str)
	{
		input_str = ft_strdup(save_str);
		free(save_str);
		save_str = NULL;
	}
	else
		input_str = ft_strdup("");
	if (!input_str)
		return (cleanup(&input_str, &save_str));
	bytes_read = read_from_fd(fd, &input_str, &save_str);
	if (bytes_read == -1)
		return (cleanup(&input_str, &save_str));
	return (finalize_line(&input_str, &save_str, bytes_read));
}
