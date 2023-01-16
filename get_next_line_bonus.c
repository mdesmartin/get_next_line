/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:00:44 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/16 16:14:11 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean(char *stash)
{
	int		i;
	int		j;
	char	*cleaned;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	cleaned = malloc(sizeof(char) * ft_strlen(stash) - i + 1);
	if (!(cleaned))
		return (free(stash), stash = NULL, NULL);
	i++;
	ft_strlcpy(cleaned, &stash[i], ft_strlen(stash) - i + 1);
	return (free(stash), stash = NULL, cleaned);
}

char	*fill(char *stash, char *line)
{
	int	i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!(line))
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*read_n_join(char *stash, int fd)
{
	int		readed;
	char	buf[BUFFER_SIZE + 1];

	if (!(stash))
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	readed = 1;
	while (readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		buf[readed] = '\0';
		stash = add_to_stash(stash, buf);
		if (!stash)
			return (NULL);
		if (ft_strrchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = NULL;
	stash[fd] = read_n_join(stash[fd], fd);
	if (!stash[fd])
		return (stash[fd] = NULL, NULL);
	line = fill(stash[fd], line);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = clean(stash[fd]);
	return (line);
}
