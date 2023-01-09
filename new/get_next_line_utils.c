/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:14 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/09 16:02:17 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

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

	if (!s1)
		return (NULL);
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	l_s1 = strlen(s1);
	l_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (!(str))
		return (NULL);
	if (s1)
		ft_strlcpy(str, s1, l_s1 + 1);
	ft_strlcpy(str + l_s1, s2, l_s2 + 1);
	free(s1);
	s2[0]= '\0';
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*str_src;
	char		*str_dst;

	if (!dst && !src)
		return (dst);
	str_dst = dst;
	str_src = src;
	if (str_dst < str_src)
	{
		while (len-- > 0)
			*str_dst++ = *str_src++;
		*str_dst = '\0';
	}
	else
	{
		str_src = src + (len - 1);
		str_dst = dst + (len);
		*str_dst-- = '\0';
		while (len-- > 0)
			*str_dst-- = *str_src--;
	}
	return (dst);
}
