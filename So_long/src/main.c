/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:31:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/22 11:04:03 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_exit(game, "Error\nCouldn't initialize mlx.", 2);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->cols * TILE,
			game->rows * TILE, "so_long");
	if (!game->win_ptr)
		ft_error_exit(game, "Error\nCouldn't create window.", 2);
	init_game(game); 
}

void	so_long(char *file)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	map_reading(&game, file);
	ft_map_check(&game);
	init_mlx(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, ft_keypress, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, ft_quit, &game);
	mlx_loop(game.mlx_ptr);
}

int	check_argument(char *arg)
{
	int	i;

	i = ft_strlen(arg);
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b'
		|| arg[i - 4] != '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error_exit(NULL, "Error\nUsage: ./so_long 'name'.ber.", 2);
	if (check_argument(av[1]) == 1)
		ft_error_exit(NULL, "Error\nInvalid file extension.", 2);
	so_long(av[1]);
	return (0);
}
