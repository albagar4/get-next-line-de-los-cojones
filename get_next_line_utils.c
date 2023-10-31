/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:34:01 by albagar4          #+#    #+#             */
/*   Updated: 2023/10/31 20:02:34 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	ft_identifier(char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)c)
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
	{
		if (str1)
			free(str1);
		if (str2)
			free(str2);
		return (NULL);
	}
	i = 0;
	while (str1 && str1[i] != '\0')
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j] != '\0')
		joined[i++] = str2[j++];
	joined[i] = '\0';
	return (joined);
}

char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;

	length = 0;
	while (src[length] != '\0')
		length++;
	copy = malloc(sizeof(char) * length + 1);
	if (!copy)
		return (NULL);
	length = 0;
	while (src[length])
	{
		copy[length] = src[length];
		length++;
	}
	copy[length] = '\0';
	return (copy);
}
