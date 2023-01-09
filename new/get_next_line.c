/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:19 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/09 16:04:33 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	clean(char *buf)
{
	int		i;

	i = 0;
	if (!buf)
		return ;
	if (buf[i] == '\0')
		return ;
	while (buf[i] != '\n')
	{
		i++;
	}
	if (i + 1 == BUFFER_SIZE)
		buf[0] = '\0';
	else
	{
		ft_memmove(buf, buf + i + 1, ft_strlen(buf + i + 1));
	}
}

char	*fill(char *stash, char *line)
{
	int	i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!(line))
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	stash = NULL;
	free(stash);
	return (line);
}

char	*read_n_join(char *stash, int fd, char *buf)
{
	int			readed;

	readed = 1;
	while (readed)
	{
		if (buf[0] == '\0')
		{
			readed = read(fd, buf, BUFFER_SIZE);
		}
		if (readed < 0)
		{
			buf[0] = '\0';
			return (NULL);
		}
		if (!stash)
		{
			stash = malloc(sizeof(char));
			stash[0] = '\0';
		}
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*stash;
	char		*line;
	static char	buf[BUFFER_SIZE + 1] = "\0";

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line = NULL;
	stash = read_n_join(stash, fd, buf);
	line = fill(stash, line);
	clean(buf);
	return (line);
}

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *str;

	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		if (!str)
			return (0);
	}
}
