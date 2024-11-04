/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:19:40 by migupere          #+#    #+#             */
/*   Updated: 2024/11/04 17:27:48 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_step_direction(double dir)
{
	if (dir < 0)
		return (-1);
	else
		return (1);
}

void	calculate_delta_distances(t_game *game)
{
	// if (dda.->ray_dir.x == 0)
	// 	dda.->delta_dist.x = HUGE_VAL;
	// else
		game->ray.delta_dist.x = fabs(1 / game->ray.ray_dir.x);
	// if (dda.->ray_dir.y == 0)game->ray.hit = false;
	// 	dda.->delta_dist.y = HUGE_VAL;
	// else
		game->ray.delta_dist.y = fabs(1 / game->ray.ray_dir.y);
}

void	calculate_side_distances(t_game *game)
{
	if (game->ray.ray_dir.x < 0)
	{
		game->ray.side_dist.x = (game->player->position_x - game->player->init_pos_x) * game->ray.delta_dist.x;
	}
	else
	{
		game->ray.side_dist.x = (game->player->init_pos_x + 1.0 - game->player->position_x)
			* game->ray.delta_dist.x;
	}
	if (game->ray.ray_dir.y < 0)
	{
		game->ray.side_dist.y = (game->player->position_y - game->player->init_pos_y)
			* game->ray.delta_dist.y;
	}
	else
	{
		game->ray.side_dist.y = (game->player->init_pos_y + 1.0 - game->player->position_y)
			* game->ray.delta_dist.y;
	}
}

void	perform_dda(t_game *game)
{
	int	hit;
	// t_dda	*dda;

	hit = false;
	
	while(!hit)
	{
		if (game->ray.side_dist.x < game->ray.side_dist.y)
		{
			game->ray.side_dist.x += game->ray.delta_dist.x;
			game->player->init_pos_x += game->ray.step.x;
			game->ray.hit = true;
		}
		else
		{
			game->ray.side_dist.y += game->ray.delta_dist.y;
			game->player->init_pos_y += game->ray.step.y;
			game->ray.hit = false;
		}
		if (game->map->map2d[(int)game->player->init_pos_y][(int)game->player->init_pos_x] == '1')
			hit = true;
	}
	// if (dda.->side == 0)
	// 	dda.->perp_wall_dist = dda.->side_dist.x - dda.->delta_dist.x;
	// else
	// 	dda.->perp_wall_dist = dda.->side_dist.y - dda.->delta_dist.y;
}

int	draw_rays(t_game *game)
{
	int		x;
	double	camera_x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		 printf("camera_x: %f\n", camera_x);

    // Print dos valores do vetor `dir` do jogador
    printf("Player direction vector: dir.x = %f, dir.y = %f\n", game->player->dir.x, game->player->dir.y);

    // Print dos valores do vetor `plane` do jogador
    printf("Player plane vector: plane.x = %f, plane.y = %f\n", game->player->plane.x, game->player->plane.y);
		game->ray.ray_dir.x = game->player->dir.x + game->player->plane.x
			* camera_x;
		game->ray.ray_dir.y = game->player->dir.y + game->player->plane.y
			* camera_x;
		 printf("Ray direction vector: ray_dir.x = %f, ray_dir.y = %f\n", game->ray.ray_dir.x, game->ray.ray_dir.y);

		game->player->init_pos_x = (int)game->player->position_x;
		game->player->init_pos_y = (int)game->player->position_y;
		game->ray.step.x = get_step_direction(game->ray.ray_dir.x);
		game->ray.step.y = get_step_direction(game->ray.ray_dir.y);
		calculate_delta_distances(game);
		calculate_side_distances(game);
		perform_dda(game);
		draw_walls_and_background(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	return (0);
}
