/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:19 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/06 16:31:52 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*clean(char *stash)
{
	int		i;
	char	*cleaned;

	i = 0;
	if (!stash)
		return (NULL);
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\n')
	{
		i++;
	}
	i++;
	cleaned = malloc(sizeof(char) * ft_strlen(stash) - i + 1);
	if (!(cleaned))
		return (NULL);
	ft_strlcpy(cleaned, &stash[i], ft_strlen(stash) - i + 1);
	// free(stash);
	return (cleaned);
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
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*read_n_join(int fd)
{
	int		readed;
	char	*stash;
	char	buf[BUFFER_SIZE + 1];

	readed = 1;
	while (readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			buf[0] = '\0';
			return (NULL);
		}
		buf[readed] = '\0';
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line = NULL;
	stash = read_n_join(fd);
	// printf("\nrnj = %s", stash);
	line = fill(stash, line);
	// printf("\nfill = %s", line);
	stash = clean(stash);
	// printf("\ncleaned = %s", stash);
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// //		printf("%s", str);
// //		free(str);
// 		str = get_next_line(fd);
// 	}
// //	printf("%s", str);
// //	free(str);
// }
