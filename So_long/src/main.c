/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:31:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/06 18:09:20 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_exit(game, "Couldn't initialize mlx.", 2);
	//loading textures?
	game->win = mlx_new_window(game->mlx, 600, 400, "hi :)");
	if (!game->win)
		ft_error_exit(game, "Couldn't create the window :(", 2)
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

int	main(int ac, char *av)
{
	if (ac != 2)
		ft_error_exit((void), "Usage: ./so_long <map_name>.ber.\n", 2);

	if (check_argument(av[1]))
		ft_error_exit((void), "Invalid file extension.\n", 2);
	so_long();
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