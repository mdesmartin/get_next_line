include "get_next_line.h"

static char	*check_buffer(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		can_read;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	can_read = 1;
	while (can_read)
	{
		can_read = read(fd, buffer, BUFFER_SIZE);
		if (can_read < 0)
			return (NULL);
		buffer[can_read] = '\0';
		stash = gnl_str_join(stash, buffer);
		//stash = add_to_stash(stash, buffer);
		if (!stash)
			return (NULL);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*fill_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	//while (stash[i] && stash[i] != '\n' )
	while (stash[i] != '\n' )
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	temp = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return (free(stash), stash = NULL, NULL);
	i++;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	return (free(stash), stash = NULL, temp);
}

/**
 * @brief Get the next line object and return it
 *
 * @param fd file descriptor
 * @return char* line read or NULL if nothing to read or an error occurs
 * (includes the '\n' except if EOS does not end with a '\n')
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	stash = check_buffer(fd, stash);
	if (!stash)
		return (stash = NULL, NULL);
	line = fill_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = clean_stash(stash);
	return (line);
}