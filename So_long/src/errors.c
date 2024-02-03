/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/24 21:34:29 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_textures(t_game *game)
{
	if (game->barrier)
		mlx_destroy_image(game->mlx_ptr, game->barrier);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->collectable)
		mlx_destroy_image(game->mlx_ptr, game->collectable);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->exit_open)
		mlx_destroy_image(game->mlx_ptr, game->exit_open);
	if (game->above_exit)
		mlx_destroy_image(game->mlx_ptr, game->above_exit);
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_array(game->map);
		free_textures(game);
		if (game->mlx_ptr && game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
	}
}

int	ft_error_exit(t_game *game, char *msg, int fd)
{
	if (fd == 2)
	{
		ft_putendl_fd(msg, fd);
		if (game)
			free_game(game);
		exit(1);
	}
	ft_putendl_fd(msg, fd);
	free_game(game);
	exit(0);
}

int	ft_quit(t_game *game)
{
	ft_error_exit(game, "You gave up. 😢", 1);
	return (0);
}
