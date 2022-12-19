/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:57:26 by mvogel            #+#    #+#             */
/*   Updated: 2022/12/19 17:00:05 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


check
{
	a = 0;
	while (a <= ft_strlen(buf))
	{
		if (buf[a] == '\n';)
			stash = endline(buf, a); //valeur quon va print
			new())
		a++;
	}
	stash = strjoin(stash, buf);
	return (stash);
}

char	*new()
{
	char *line;

	line = strchr(buf, '\n');
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	int			p;

	while (rread(fd, buf))
	{
		check(buf,)
	}

	while (pas de /n && p == BUFFER_SIZE)
	{
		p = read(fd, buf ,BUFFER_SIZE);
		if (p == -1)
			return (NULL);
		if 
		strjoin (stash, buf)
	}
	strjoin (stash, buf avant \n));
	res = stash; +\n 0 la fin
	stash = buf apres \n jusauq n


	line = stash
	stast = new();
	return (line);
}


{
	
}
// lire et join le buffer a chaque fois, puis ensuite lire et si /n on garde ce auil y a avant puis on met de cot2 de auil reste

void	after_end()
{
	buf = ft_strrchr(buf, \n)
}

void	before_end()
{
	char	*buf;
	int		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readed = read(fd, buf, BUFFER_SIZE);
	if (readed == 0 || ft_strchr(buf, '\n')) // et si il renvoyais la position du /n 
	{
		return (ft_strjoin(stash, strchr(buf, '\n')));
	}
	stash = ft_strjoin(stash, buf);
	free(buf);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL)
	stash = before_end()

	buf = after_end();
}

int	main()
{
	open()
}
