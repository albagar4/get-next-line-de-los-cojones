/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:34:05 by albagar4          #+#    #+#             */
/*   Updated: 2023/10/24 17:43:48 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1000

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_identifier(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*joined;

	joined = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!joined)
		return (free(str1), free(str2), free(joined), NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		joined[i] = str2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*preserve_text(char *stash)
{
	int		length;
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (ft_identifier(stash, '\n') == -1)
	{
		rest = (char *)malloc(sizeof(char) * 1);
		if (!rest)
			return (free(rest), free(stash), NULL);
		rest[i] = '\0';
		return (free(stash), rest);
	}
	length = (ft_strlen(stash) - ft_identifier(stash, '\n'));
	j = ft_identifier(stash, '\n') + 1;
	rest = (char *)malloc(length * sizeof(char));
	if (!rest)
		return (free(rest), free(stash), NULL);
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
	int	i;

	i = 0;
	if (!stash)
	{
		stash = (char *)malloc(ft_strlen(buffer) * sizeof(char));
		if (!stash)
			return (free(buffer), free(stash), NULL);
		while (i < (ft_strlen(buffer) + 1))
		{
			stash[i] = buffer[i];
			i++;
		}
	}
	stash = ft_strjoin(preserve_text(stash), buffer);
	return (stash);
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
	line = (char *)malloc((length * sizeof(char)) + 1);
	if (!line)
		return (free(line), NULL);
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
	int			i;

	numbytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (numbytes > 0)
	{
		if (numbytes == -1)
			return (NULL);
		numbytes = read(fd, buffer, BUFFER_SIZE);
		stash = update_stash(stash, buffer);
		if (ft_identifier(buffer, '\n') != -1)
			break ;
	}
	printf("stash 1: %s\n", stash);
	line = read_this_line(stash);
	stash = preserve_text(stash);
	printf("line tiene dentro: %s\n", line);
	printf("stash 2: %s\n\n", stash);
	if (numbytes == 0 && line == NULL)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texto.txt", O_RDONLY);
	printf("fd tiene un valor de: %i\n", fd);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		//printf("line en el main es: %s\n", line);
	}
	close (fd);
	return (0);
}
