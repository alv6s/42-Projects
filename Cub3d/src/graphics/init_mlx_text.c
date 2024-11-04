/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:51:15 by migupere          #+#    #+#             */
/*   Updated: 2024/11/04 16:42:58 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	check_init(void *ptr, t_game *game, const char *error_message)
// {
// 	if (!ptr)
// 		ft_perror((char)error_message, game);
// }

void	load_textures(t_game *game)
{
	int		i;
	char	**texture_paths =(char **)malloc((int)NBR_TEXTURES * sizeof(char *));

	i = 0;
	texture_paths[0] = game->map->north;
	texture_paths[1] = game->map->east;
	texture_paths[2] = game->map->west;
	texture_paths[3] = game->map->south;
	while (i < 4)
	{
		game->render[i].img = mlx_xpm_file_to_image(game->mlx,
				texture_paths[i], &game->render[i].width,
				&game->render[i].height);
		if (!game->render[i].img)
			perror("Error:\nFailed to load texture\n");
		game->render[i].addr = mlx_get_data_addr(game->render[i].img,
				&game->render[i].bpp, &game->render[i].line_len,
				&game->render[i].endian);
		if (!game->render[i].addr)
			perror("Error:\nFailed to get texture address\n");
		i++;
	}
	free(texture_paths);
}

void	init_mlx_and_textures(t_game *game)
{
	game->mlx = mlx_init();
	if(!game->mlx)
		perror("Error:\nFailed to initialize mlx\n");
	load_textures(game);
	game->screen->width = (int)SCREEN_WIDTH;
	game->screen->height = (int)SCREEN_HEIGHT;
	game->screen->img = mlx_new_image(game->mlx,
			game->screen->width, game->screen->height);
	if(!game->screen->img)
		perror("Error:\nFailed to create new image\n");
	game->screen->addr = mlx_get_data_addr(game->screen->img,
			&game->screen->bpp, &game->screen->line_len, &game->screen->endian);
	if(!game->screen->addr)
		perror("Error:\nFailed to get image address\n");
	game->win = mlx_new_window(game->mlx, game->screen->width,
			game->screen->height, "CUB3D");
	if(!game->win)
		perror("Error:\nFailed to create new window\n");
}
