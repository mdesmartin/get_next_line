/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:19 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/05 17:29:48 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean(char *stash)
{
	int		i;
	int		j;
	char	*cleaned;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	i++;
	while (stash[i] != '\0')
	{
		cleaned[j++] = stash[i++];
	}
	cleaned[j] = '\0';
	return (cleaned);
}

char	*fill(char *stash, char *line)
{
	int	i;

	i = 0;
	while (stash && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*read_n_join(int fd)
{
	int		readed;
	char	*stash;
	char	*buf;

	readed = 1;
	while (readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char *stash;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stash = read_n_join(fd);
	line = fill(stash, line);
	stash = clean(stash);
	return (line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
