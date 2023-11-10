
    Is the next move valid?
    Does the next move cause a special event 
	(either winning the game, collecting a collectable, or in the case of a bonus, hitting an enemy)?



static void	render_map(t_game *game, int i, int j)
{
	t_img	*tile;

	tile = &game->img_walls;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.grid[i][j] == '1')
				tile = &game->img_walls;
			else if (game->map.grid[i][j] == '0')
				tile = &game->img_space;
			else if (game->map.grid[i][j] == 'E')
				tile = &game->img_exit;
			else if (game->map.grid[i][j] == 'C')
				tile = &game->img_collect;
			else if (game->map.grid[i][j] == 'P')
				tile = &game->img_p[0];
			mlx_put_image_to_window(game->mlx, game->win, tile->img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

static void	check_textures(t_game *game)
{
	if (!game->img_walls.img || !game->img_space.img || !game->img_exit.img
		|| !game->img_collect.img
		|| !game->img_p[0].img || !game->img_p[1].img)
		exit_error(game, "Couldn't load textures.");
}

static void	load_textures(t_game *game)
{
	g->img_walls.img = mlx_xpm_file_to_image(g->mlx, "game_images/floor.xpm", &g->x, &g->y);
	g->img_space.img = mlx_xpm_file_to_image(g->mlx, S_XPM, &g->x, &g->y);
	g->img_exit.img = mlx_xpm_file_to_image(g->mlx, E_XPM, &g->x, &g->y);
	g->img_collect.img = mlx_xpm_file_to_image(g->mlx, C1_XPM, &g->x, &g->y);
	g->img_p[0].img = mlx_xpm_file_to_image(g->mlx, P1_XPM, &g->x, &g->y);
	g->img_p[1].img = mlx_xpm_file_to_image(g->mlx, P2_XPM, &g->x, &g->y);
	check_textures(g);
}

void	init_game(t_game *game)
{
	map_reading(game, char **argv)
	init_mlx_and_textures(game);
	load_textures(game)
	render_map(game, -1, -1);
}