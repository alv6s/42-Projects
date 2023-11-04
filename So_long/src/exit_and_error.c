/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/04 18:48:48 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
