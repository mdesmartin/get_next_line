/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:49 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/09 16:07:15 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_n_join(char *stash, int fd);
char	*fill(char *stash, char *line);
char	*clean(char *stash);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

#endif