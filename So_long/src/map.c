/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:05 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/24 21:36:44 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	map_columns(char *string)
{
	int	columns;

	columns = 0;
	while (string[columns] != '\0')
		columns++;
	if (string[columns - 1] == '\n' && columns != 0)
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
		ft_error_exit(game, "Error\nCouldn't open the file.", 2);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!add_row(game, line))
			break ;
	}
	close (game->fd);
	if (!game->map)
		ft_error_exit(game, "Error\nMap is empty.", 2);
	game->cols = map_columns(game->map[0]);
	return (1);
}

int	ft_check_path(t_game *game)
{
	int		path_result;
	char	**map_cpy;

	game->y = 0;
	path_result = 0;
	map_cpy = ft_calloc(game->rows + 1, sizeof(char *));
	if (!map_cpy)
		ft_error_exit(game, "Error\nMalloc failed.", 2);
	while (game->y < game->rows)
	{
		map_cpy[game->y] = ft_strdup(game->map[game->y]);
		{
			if (!game->map[game->y])
			{
				free_array(map_cpy);
				ft_error_exit(game, "Error\nMalloc failed.", 2);
			}
		}
		game->y++;
	}
	path_result = ft_flood_fill(game, map_cpy, game->player_y, game->player_x);
	free_array(map_cpy);
	return (path_result);
}

int	ft_flood_fill(t_game *game, char **map, int y, int x)
{
	int			n_collectables;
	static int	c;
	static int	e;

	n_collectables = game->collectables;
	if (map[y][x] == '1')
		return (0);
	else if (map[y][x] == 'C')
		c += 1;
	else if (map[y][x] == 'E')
		e += 1;
	map[y][x] = '1';
	ft_flood_fill(game, map, y + 1, x);
	ft_flood_fill(game, map, y - 1, x);
	ft_flood_fill(game, map, y, x + 1);
	ft_flood_fill(game, map, y, x - 1);
	if (c == n_collectables && e == 1)
		return (1);
	else
		return (0);
}
