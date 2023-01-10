/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:14 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/10 15:28:15 by mvogel           ###   ########lyon.fr   */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		l_s1;
	int		l_s2;
	char	*str;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, s1, l_s1 + 1);
	ft_strlcpy(str + l_s1, s2, l_s2 + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (a <= ft_strlen(s))
	{
		if (s[a] == (char)c)
			return (((char *) s) + a);
		a++;
	}
	return (0);
}

char	*add_to_stash(char *stash, char *buffer)
{
	char	*dst;

	dst = ft_strjoin(stash, buffer);
	free(stash);
	stash = NULL;

	return (dst);
}
