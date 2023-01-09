/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:49 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/09 15:43:24 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_n_join(char *stash, int fd, char *buf);
char	*fill(char *stash, char *line);
void	clean(char *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif