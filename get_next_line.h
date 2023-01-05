/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:49 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/05 16:03:49 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB
# define LIB
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_n_join(int fd);
char	*fill(char *stash, char *line);
char	*clean(char *stash);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif