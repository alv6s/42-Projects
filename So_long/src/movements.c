/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:09:30 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/21 18:51:30 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_open_exit(t_game *game)
{
	game->collectables--;
	if (game->collectables == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit_open, game->exit_x * TILE, game->exit_y * TILE);
	}
}

static int	ft_move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->floor, game->player_x * TILE, game->player_y * TILE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player, x * TILE, y * TILE);
		if (game->map[y][x] == 'C')
			ft_open_exit(game);
		game->map[game->player_y][game->player_x] = '0';
		game->map[y][x] = '0';
		game->player_x = x;
		game->player_y = y;
		game->counter++;
		return (1);
	}
	if (game->map[y][x] == 'E' && game->collectables == 0)
	{
		ft_printf("Moves: %i\n", game->counter + 1);
		ft_error_exit(game, "Yay! The mouse is full! ^^\n", 1);
	}
	return (0);
}

int	ft_keypress(int keycode, t_game *game)
{
	int	to_print;

	to_print = 0;
	if (keycode == ESC)
		ft_error_exit(game, "You gave up! :(", 1);
	else if (keycode == UP)
		to_print = ft_move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == LEFT)
		to_print = ft_move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == DOWN)
		to_print = ft_move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == RIGHT)
		to_print = ft_move_player(game, game->player_x + 1, game->player_y);
	if (to_print == 1)
		ft_printf("Moves: %i\n", game->counter);
	return (0);
}
