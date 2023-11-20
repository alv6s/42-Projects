/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:31:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/20 22:07:48 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_exit(game, "Couldn't initialize mlx.", 2);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->cols * TILE,
			game->rows * TILE, "so_long");
	if (!game->win_ptr)
		ft_error_exit(game, "Couldn't create window.", 2);
	init_game(game); 
}

void	so_long(char *file)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	map_reading(&game, file);
	ft_map_check(&game);
	init_mlx(&game);
	mlx_hook(game.mlx_ptr, 2, 1L << 0, ft_keypress, &game);
	mlx_hook(game.mlx_ptr, 17, 1L << 17, ft_error_exit, &game);
	mlx_loop(game.mlx_ptr);
	printf("passou1");
}

int	check_argument(char *argument)
{
	int	i;

	i = ft_strlen(argument);
	if (argument[i - 1] != 'r' || argument[i - 2] != 'e' || argument[i - 3] != 'b'
			|| argument[i - 4] != '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error_exit(NULL, "Usage: ./so_long <map_name>.ber.\n", 2);

	if (check_argument(av[1]) == 1)
		ft_error_exit(NULL, "Invalid file extension.\n", 2);
	so_long(av[1]);
	return (0);
}