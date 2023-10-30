/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:34:01 by albagar4          #+#    #+#             */
/*   Updated: 2023/10/30 19:38:42 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)malloc(count * size);
	if (!str)
		return (free(str), NULL);
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

char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;

	length = 0;
	while (src[length] != '\0')
		length++;
	copy = malloc(sizeof(char) * length + 1);
	if (!copy)
		return (0);
	length = 0;
	while (src[length])
	{
		copy[length] = src[length];
		length++;
	}
	copy[length] = '\0';
	return (copy);
}
