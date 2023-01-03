/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:57:26 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/03 16:01:24 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	after_end()
// {
// 	buf = ft_strrchr(buf, \n)
// }

char	*before_end(int fd)
{
	char	*buf;
	char	*stash; //init?
	int		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = read(fd, buf, BUFFER_SIZE);
	if (readed == 0 || ft_strchr(buf, '\n'))
	{
		return (ft_strjoin(stash, xxx), free(buf), buf = strchr(buf, '\n'));
	}
	else
	{
		stash = ft_strjoin(stash, buf);
		free(buf);
		before_end(fd);
	}
}

char	*get_next_line(int fd)
{
	char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stash = before_end(fd);
	line = NULL;
//	after_end();
	return (stash);
}






#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
}
