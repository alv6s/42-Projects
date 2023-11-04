/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:30:20 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/04 18:52:54 by pevieira         ###   ########.fr       */
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