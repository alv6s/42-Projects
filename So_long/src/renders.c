/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:47 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/19 22:45:26 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < game->rows)
	{
		x = 0;
		while (x++ < game->cols)
		{
			if (game->map[y][x] == '1')
				game->img = &game->barrier;  //pq tem o endereco
			else if (game->map[y][x] == '0')
				game->img = &game->floor;
			else if (game->map[y][x] == 'E')
				game->img = &game->exit;
			else if (game->map[y][x] == 'C')
				game->img = &game->collectable;
			else if (game->map[y][x] == 'P')
				game->img = &game->player;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img,
				x * TILE, y * TILE);
		}
	}
}

static void	check_textures(t_game *game)
{
	if (!game->barrier || !game->floor || !game->exit
		|| !game->collectable || !game->player)
		ft_error_exit(game, "Couldn't load textures", 2);
}

static void	load_textures(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "img/0.xpm", &game->x, &game->y);
	game->barrier = mlx_xpm_file_to_image(game->mlx_ptr, "img/1.xpm", &game->x, &game->y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "img/e1.xpm", &game->x, &game->y);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "img/p.xpm", &game->x, &game->y);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, "img/c.xpm", &game->x, &game->y);
	check_textures(game);
}

void	init_game(t_game *game)
{
	//map_reading(game);  
	//init_mlx_and_textures(game);
	load_textures(game);
	render_map(game);
}