/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:31:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/10 15:18:51 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Couldn't initialize mlx.");
	load_textures(game);
	game->win = mlx_new_window(game->mlx, game->map.cols * TILE_SIZE,
			game->map.rows * TILE_SIZE, "so_long");
	if (!game->win)
		exit_error(game, "Couldn't create window.");
}

void	so_long()
{
	t_game	*game;

	ft_bzero(&game, sizeof(t_game));
	init_mlx(t_game *game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}

bool	check_argument(char *argument)
{
	int	i;

	i = ft_strlen(argument);
	if (argument[i - 1] != 'r' || argument[i - 2] != 'e' || argument[i - 3] != 'b'
			|| argument[i - 4] != '.')
		return (true);
	return (false);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error_exit((void), "Usage: ./so_long <map_name>.ber.\n", 2);

	if (check_argument(av[1]))
		ft_error_exit((void), "Invalid file extension.\n", 2);
	so_long();
}