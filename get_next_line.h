/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:33:56 by albagar4          #+#    #+#             */
/*   Updated: 2023/10/30 19:16:16 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*preserve_text(char *stash);
char	*update_stash(char	*stash, char *buffer);
char	*read_this_line(char *stash);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *str);
int		ft_identifier(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *src);

#endif
