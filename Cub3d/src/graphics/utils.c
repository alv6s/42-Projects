/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:20:18 by migupere          #+#    #+#             */
/*   Updated: 2024/11/04 17:33:26 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void	define_initial_plane(t_game *game)
{
	printf("a direçao do player é: %c\n", game->player->direction);
	if (game->player->direction == 'N')
		game->player->dir = create_vector(0, -1);
	else if (game->player->direction == 'S')
		game->player->dir = create_vector(0, 1);
	else if (game->player->direction == 'W')
		game->player->dir = create_vector(-1, 0);
	else if (game->player->direction == 'E')
		game->player->dir = create_vector(1, 0);
	printf("oii\n");
  	printf("Os valores do vetor de direcao: x = %f, y = %f\n", game->player->dir.x, game->player->dir.y);
	game->player->plane.x = -game->player->dir.y;
	game->player->plane.y = game->player->dir.x;
	 printf("Os valores do vetor de direção após definir o plano: x = %f, y = %f\n", game->player->dir.x, game->player->dir.y);
    printf("Os valores do vetor do plano: x = %f, y = %f\n", game->player->plane.x, game->player->plane.y);
}

// void	ft_perror(char *msg, t_game *game)
// {
// 	int	i;

// 	i = -1;
// 	printf("%s", msg);
// 	if (!game)
// 		exit (EXIT_FAILURE);
// 	while (++i < 4)
// 	{
// 		if (game->render[i].img)
// 			mlx_destroy_image(game->mlx, game->render[i].img);
// 	}
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		free (game->mlx);
// 	}
	
// 	if (game->map->map2d)
// 		free_arr(game->map->map2d);
// 	exit (EXIT_SUCCESS);
// }