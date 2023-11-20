/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:05 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/20 23:07:16 by pevieira         ###   ########.fr       */
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

void	ft_map_check(t_game *game)
{
	if (game->rows < 3 || game->cols < 5)
		ft_error_exit(game, "Error\nMap too small\n", 2);
	if (ft_check_characters(game) == 0)
		ft_error_exit(game, "Error\nWrong number of characters\n", 2);
	if (ft_check_retangular(game) == 0)
		ft_error_exit(game,"Map is not retangulasr\n", 2);
	if (ft_check_walls(game) == 0)
		ft_error_exit(game, "Error\nNot surrounded by walls\n", 2);
	if (ft_check_path(game) == 0)
		ft_error_exit(game, "Error\nNo valid path\n", 2);
}

int	ft_check_characters(t_game *game)
{
	game->y = 0;
	while (game->y < game->rows)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			if (game->map[game->y][game->x] == 'C')
				game->collectables++;
			else if (game->map[game->y][game->x] == 'E')
				game->exitcount++;
			else if (game->map[game->y][game->x] == 'P')
			{
				game->playercount++;
				game->player_x = game->x;
				game->player_y = game->y;
			}
			else if (ft_strchr("01CEP", game->map[game->y][game->x]) == 0)
				ft_error_exit(game, "Error\nWrong character was found\n", 2);
			game->x++;
		}
		game->y++;
	}
	return (game->collectables >= 1 && game->exitcount == 1
		&& game->playercount == 1);
}

int	ft_check_retangular(t_game *game)
{
	game->y = 0;

	while (game->y < game->rows)
	{
		if ((int)ft_strlen(game->map[game->y]) != game->cols)
			return (0);
		game->y++;
	}
	return (1);
}


int	ft_check_walls(t_game *game)
{
	game->y = 0;
	while (game->y < game->rows)
	{
		if (game->map[game->y][0] != '1'
				|| game->map[game->y][game->cols - 1] != '1')
			return (0);
		game->y++;
	}
	game->x = 0;
	while (game->x < game->cols)
	{
		if (game->map[0][game->x] != '1'
				|| game->map[game->rows - 1][game->x] != '1')
			return (0);
		game->x++;
	}
	return (1);
}

// check if the map has a valid path (all 0 are connected to the player)
int	ft_check_path(t_game *game)
{
	int		path_result;
	char	**map_cpy;

	game->y = 0;
	path_result = 0;
	map_cpy = ft_calloc(game->rows + 1, sizeof(char *));
	if (!map_cpy)
		ft_error_exit(game, "Error\nMalloc failed\n", 2);
	while (game->y < game->rows)
	{
		map_cpy[game->y] = ft_strdup(game->map[game->y]);
		{
			if (!game->map[game->y])
			{
				free_array(map_cpy);
				ft_error_exit(game, "Error\nMalloc failed\n", 2);
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