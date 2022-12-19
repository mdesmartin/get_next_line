/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:24:19 by mvogel            #+#    #+#             */
/*   Updated: 2022/12/19 15:37:04 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

	// if (!(s1))
	// 	return (NULL); malloc 1 et mettre \0
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

char	*ft_strrchr(const char *s, int c) // bollein valeur return ? 1 si trouv2
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
