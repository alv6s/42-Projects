/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:48:01 by pevieira          #+#    #+#             */
/*   Updated: 2023/07/27 09:43:40 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *static_buffer)
{
	int		bytes_read;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(static_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE); // read from fd to temp
		if (bytes_read == -1) // if read fails
		{
			free(temp);
			free(static_buffer);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		static_buffer = ft_strjoin_gnl(static_buffer, temp); // join temp to static_buffer (stash)
	}
	free(temp);
	if (ft_strlen_gnl(static_buffer) != 0) // if static_buffer is not empty
		return (static_buffer);
	free(static_buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line_to_get(stash);
	stash = ft_rest(stash);
	return (line);
}
/*
int	main()
{
	int		fd = open("tests.txt", O_RDONLY);
	char	*line = get_next_line(fd);

	if (fd == -1)
		return (1);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}*/