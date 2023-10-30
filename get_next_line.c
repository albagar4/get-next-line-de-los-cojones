/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:34:05 by albagar4          #+#    #+#             */
/*   Updated: 2023/10/30 19:49:31 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*preserve_text(char *stash)
{
	int		length;
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (ft_identifier(stash, '\n') == -1)
	{
		rest = ft_calloc(1, sizeof(char));
		if (rest == NULL)
			return (NULL);
		return (free(stash), rest);
	}
	length = (ft_strlen(stash) - ft_identifier(stash, '\n'));
	j = ft_identifier(stash, '\n') + 1;
	rest = ft_calloc(length, sizeof(char));
	if (rest == NULL)
		return (NULL);
	while (i < length)
	{
		rest[i] = stash[j];
		i++;
		j++;
	}
	rest[i] = '\0';
	return (free(stash), rest);
}

char	*update_stash(char	*stash, char *buffer)
{
	char	*new_stash;

	if (!stash)
	{
		new_stash = ft_strdup(buffer);
		if (!new_stash)
			return (free(new_stash), NULL);
	}
	else
		new_stash = ft_strjoin(stash, buffer);
	free(stash);
	return (new_stash);
}

char	*read_this_line(char *stash)
{
	int		i;
	int		length;
	char	*line;

	length = ft_identifier(stash, '\n');
	if (length == -1)
		return (NULL);
	i = 0;
	line = ft_calloc(length + 1, sizeof(char));
	if (!line)
		return (0);
	while (i <= length)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			numbytes;

	numbytes = 1;
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (free(stash), free(buffer), NULL);
	while (numbytes > 0)
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		if (numbytes == -1)
			return (free(stash), free(buffer), NULL);
		stash = update_stash(stash, buffer);
		if (ft_identifier(buffer, '\n') != -1)
			break ;
	}
	line = read_this_line(stash);
	stash = preserve_text(stash);
	free(buffer);
	return (line);
}
