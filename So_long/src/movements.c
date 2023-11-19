/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:09:30 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/19 14:04:28 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.img, game.x * SIZE, game.y * SIZE);
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.img, x * SIZE, y * SIZE);
		if (game->map[y][x] == 'C')
			game.collectables--;
		game->map[game.x][game.y] = '0';
		game->map[y][x] = '0';
		game->x = x;
		game->y = y;
		game.counter++;
		return (1);
	}
	if (game->map[y][x] == 'E' && game->collectables == 0)
	{
		ft_printf("Moves: %i\n", game.counter + 1);
		ft_printf("Congratulations, you finished the game!\n");
		ft_close_win(game);
	}
	if (to_print == 1)
		ft_printf("Moves: %i\n", game->counter);
	return (0);
}

int	ft_keypress(int keycode, t_game *game)
{
	int	to_print;

	to_print = 0;
	if (keycode == ESC)
		ft_error_exit(t_game *game, "You gave up!", 1)
	else if (keycode == UP)
		to_print = ft_move_player(game, game.y, game.x - 1);
	else if (keycode == LEFT)
		to_print = ft_move_player(game, game.y - 1, game.x);
	else if (keycode == DOWN)
		to_print = ft_move_player(game, game.y, game.x + 1);
	else if (keycode == RIGHT)
		to_print = ft_move_player(game, game.y + 1, game.x);
	if (to_print == 1)
		ft_printf("Moves: %i\n", game->moves);
	return (0);
}