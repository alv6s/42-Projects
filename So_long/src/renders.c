/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:47 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/22 12:15:28 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->cols)
		{
			if (game->map[y][x] == '1')
				game->img = game->barrier;
			else if (game->map[y][x] == '0')
				game->img = game->floor;
			else if (game->map[y][x] == 'E')
				game->img = game->exit;
			else if (game->map[y][x] == 'C')
				game->img = game->collectable;
			else if (game->map[y][x] == 'P')
				game->img = game->player;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img,
				x * TILE, y * TILE);
		}
	}
}

static void	check_textures(t_game *game)
{
	if (!game->barrier || !game->floor || !game->exit || !game->exit_open
		|| !game->collectable || !game->player || !game->above_exit)
		ft_error_exit(game, "Error\nCouldn't load textures.", 2);
}

static void	load_textures(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, 
			"img/floor.xpm", &game->x, &game->y);
	game->barrier = mlx_xpm_file_to_image(game->mlx_ptr, 
			"img/barrier.xpm", &game->x, &game->y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, 
			"img/exit.xpm", &game->x, &game->y);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, 
			"img/player.xpm", &game->x, &game->y);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, 
			"img/collectable.xpm", &game->x, &game->y);
	game->exit_open = mlx_xpm_file_to_image(game->mlx_ptr, 
			"img/exit_open.xpm", &game->x, &game->y);
	game->above_exit = mlx_xpm_file_to_image(game->mlx_ptr, 
			"img/above_exit.xpm", &game->x, &game->y);
	check_textures(game);
}

void	init_game(t_game *game)
{
	load_textures(game);
	check_textures(game);
	render_map(game);
}
