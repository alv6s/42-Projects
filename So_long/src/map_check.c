/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:14:40 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/22 00:01:26 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_save_coordinates(t_game *game, char a)
{
	if (a == 'E')
	{
		game->exit_x = game->x;
		game->exit_y = game->y;
		game->exitcount++;
	}
	if (a == 'P')
	{
		game->playercount++;
		game->player_x = game->x;
		game->player_y = game->y;
	}
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
				ft_save_coordinates(game, 'E');
			else if (game->map[game->y][game->x] == 'P')
				ft_save_coordinates(game, 'P');
			else if (ft_strchr("01CEP", game->map[game->y][game->x]) == 0)
				ft_error_exit(game, "Error\nWrong character was found.", 2);
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

void	ft_map_check(t_game *game)
{
	if (game->rows < 3 || game->cols < 3)
		ft_error_exit(game, "Error\nMap too small.", 2);
	if (ft_check_characters(game) == 0)
		ft_error_exit(game, "Error\nWrong number of characters.", 2);
	if (ft_check_retangular(game) == 0)
		ft_error_exit(game, "Error\nMap is not retangular.", 2);
	if (ft_check_walls(game) == 0)
		ft_error_exit(game, "Error\nNot surrounded by walls.", 2);
	if (ft_check_path(game) == 0)
		ft_error_exit(game, "Error\nNo valid path.", 2);
}
