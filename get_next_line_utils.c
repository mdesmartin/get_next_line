/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:14 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/07 13:59:42 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize == 0)
		return ;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char *stash, char *buffer)
{
	int		l_stash;
	int		l_buffer;
	char	*str;

	l_stash = ft_strlen(stash);
	l_buffer = ft_strlen(buffer);
	str = malloc(sizeof(char) * (l_stash + l_buffer + 1));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, stash, l_stash + 1);
	ft_strlcpy(str + l_stash, buffer, l_buffer + 1);
	return (str);
}

char	*add_to_stash(char *stash, char *buffer)
{
	char	*dst;

	dst = ft_strjoin(stash, buffer);
	free(stash);
	stash = NULL;
	return (dst);
}

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	while (a >= 0)
	{
		if (s[a] == (char)c)
			return ((char *)s + a);
		a--;
	}
	return (NULL);
}
