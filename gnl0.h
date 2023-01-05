/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl0.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:41:13 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/05 15:21:54 by mvogel           ###   ########lyon.fr   */
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

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
static char	*ft_cp(int l_s, const char *s, char *str);


char	*get_next_line(int fd);

#endif