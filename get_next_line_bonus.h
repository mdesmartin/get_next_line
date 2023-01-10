/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:02:22 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/10 18:02:40 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_n_join(char *stash, int fd);
char	*fill(char *stash, char *line);
char	*clean(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlen(const char *s);
char	*add_to_stash(char *stash, char *buffer);

#endif