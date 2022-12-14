/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:57:26 by mvogel            #+#    #+#             */
/*   Updated: 2022/12/14 10:54:40 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char	*stash;
	char	buf;
	int		i;
	int		r;

	while (count)
	{
		r = read(fd, buf ,1);
		if (buf == '\0')
			return (ajoute \n a la fin puis return);
		if (r > 0)
		{
			i += w;
			stash[i] = buf;
		}
		if (w == 0)
		{
			stash[i + 1] = '\0';
			return (stash);
		}
		else
			return (stash);
	}
	read()

	return (stash);
}

int	main()
{
	open
}