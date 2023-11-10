/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/10 16:33:43 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_textures(t_game *game)
{
	if (game->img_walls.img)
		mlx_destroy_image(game->mlx, game->img_walls.img);
	if (game->img_space.img)
		mlx_destroy_image(game->mlx, game->img_space.img);
	if (game->img_exit.img)
		mlx_destroy_image(game->mlx, game->img_exit.img);
	if (game->img_collect.img)
		mlx_destroy_image(game->mlx, game->img_collect.img);
	if (game->img_p[0].img)
		mlx_destroy_image(game->mlx, game->img_p[0].img);
	if (game->img_p[1].img)
		mlx_destroy_image(game->mlx, game->img_p[1].img);
}

void free_game(t_game *game)
{
	if (game)
	{
		if (game->map.grid)
			free_array(game->map.grid)
		free_textures(game);
		if (game->mlx && game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		exit(0)
	}
}

int	ft_error_exit(t_game *game, char *msg, int fd)
{
	if (fd == 2)
	{
		ft_putendl_fd(msg, fd);
		if (game)
			free_game(t_game *game);
		exit(1);
	}
	ft_putendl_fd(msg, fd);
	free_game(t_game *game);
	exit(0)
}


///colocar noutro sitio? 

int	exit_esc(t_game *game)
{
	ft_putendl_fd("You gave up! 🐔", 1);
	free_game(game);
	exit(EXIT_SUCCESS);
}