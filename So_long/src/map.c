/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:05 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/21 11:14:24 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	map_columns(char *string)
{
	int	columns;

	columns = 0;
	while (string[columns] != '\0')
		columns++;
	if (string[columns - 1] == '\n')
		columns--;
	return (columns);
}

static int	add_row(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->rows++;
	temporary = (char **)malloc(sizeof(char *) * (game->rows + 1));
	temporary[game->rows] = NULL;
	while (i < game->rows - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_game *game, char *file)
{
	char	*line;

	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!add_row(game, line))
			break ;
	}
	close (game->fd);
	game->cols = map_columns(game->map[0]);
	return (1);
}

