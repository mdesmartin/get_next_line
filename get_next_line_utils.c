/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:14 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/06 14:29:49 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
			dst[i] = src[i];
			i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		l_s1;
	int		l_s2;
	char	*str;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (!(str))
		return (NULL);
	if (s1)
		ft_strlcpy(str, s1, l_s1 + 1);
	ft_strlcpy(str + l_s1, s2, l_s2 + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = 0;
	while (a <= ft_strlen(s))
	{
		if (s[a] == (char)c)
			return (((char *) s) + a);
		a++;
	}
	return (0);
}
