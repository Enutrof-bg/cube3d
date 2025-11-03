/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:24:04 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 11:10:17 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*check_newline_and_extract_line(char **stash)
{
	char	*newline;
	char	*line;
	char	*temp;
	int		len;

	if (!*stash)
		return (NULL);
	newline = ft_strchr(*stash, '\n');
	if (newline)
	{
		len = newline - *stash + 1;
		line = ft_substr(*stash, 0, len);
		temp = ft_strdup(newline + 1);
		free(*stash);
		*stash = temp;
		return (line);
	}
	return (NULL);
}

static int	read_and_append_buffer(int fd, char **stash, char *buffer)
{
	int		nb_read;
	char	*temp;

	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read > 0)
	{
		buffer[nb_read] = '\0';
		if (!*stash)
			*stash = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(*stash, buffer);
			free(*stash);
			*stash = temp;
		}
	}
	return (nb_read);
}

char	*fill_line_buffer(int fd, char **stash)
{
	char	*buffer;
	char	*line;
	int		nb_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nb_read = 1;
	line = NULL;
	while (nb_read > 0 && !line)
	{
		if (!*stash)
			*stash = ft_strdup("");
		line = check_newline_and_extract_line(stash);
		if (line)
			break ;
		nb_read = read_and_append_buffer(fd, stash, buffer);
		if (nb_read < 0)
		{
			free(*stash);
			*stash = NULL;
			return (free(buffer), NULL);
		}
	}
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = fill_line_buffer(fd, &stash);
	if (!line && stash && *stash)
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
	}
	else if (!line)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
	}
	return (line);
}
