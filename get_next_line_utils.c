/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:14 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/05 15:30:19 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_cp(int l_s, const char *s, char *str)
{
	while (l_s)
	{
		*str = *s;
		str++;
		s++;
		l_s--;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l_s1;
	int		l_s2;
	int		i;
	char	*str;

	if (!(s1))
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	i = l_s1 + l_s2;
	str = malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	str = ft_cp(l_s1, s1, str);
	str = ft_cp(l_s2, s2, str);
	*str = '\0';
	return (str - i);
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
