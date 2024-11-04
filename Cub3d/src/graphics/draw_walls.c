/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:00:05 by migupere          #+#    #+#             */
/*   Updated: 2024/11/04 17:28:25 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	intersection_point(t_game *game)
{
	if (game->ray.hit == true)
		game->screen->point_x = game->player->position_y + game->ray.perp_wall_dist
			* game->ray.ray_dir.y;
	else
		game->screen->point_x = game->player->position_x + game->ray.perp_wall_dist
			* game->ray.ray_dir.x;
	game->screen->point_x -= floor(game->screen->point_x);
	
}

static void	find_texture_position_x(t_game *game)
{
	game->screen->texture_x = (int)(game->screen->point_x * TILE_SIZE);
	if ((game->ray.hit == 0 && game->ray.ray_dir.x < 0)
		|| (game->ray.hit == 1 && game->ray.ray_dir.y > 0))
		game->screen->texture_x = TILE_SIZE - game->screen->texture_x - 1;
	game->screen->texture_step = (double)game->render->height / game->screen->line_height;
}

void	*set_wall_texture(t_game *game)
{
	if (game->ray.hit == false)
	{
		if (game->ray.ray_dir.y > 0)
			game->screen->index = NORTH;
		else
			game->screen->index = SOUTH;
	}
	else
	{
		if (game->ray.ray_dir.x > 0)
			game->screen->index = WEST;
		else
			game->screen->index = EAST;
	}
}

void	draw_walls_and_background(t_game *game, int x)
{
	t_render	*texture;

	texture = set_wall_texture(game);
	if (game->ray.hit == true)
		game->ray.perp_wall_dist = game->ray.side_dist.x - game->ray.delta_dist.x;
	else
		game->ray.perp_wall_dist = game->ray.side_dist.y - game->ray.delta_dist.y;
	if (game->ray.perp_wall_dist < 0.0001)
		game->ray.perp_wall_dist = 0.5;
	game->screen->line_height = fabs(SCREEN_HEIGHT / game->ray.perp_wall_dist);
	game->screen->start_y = (SCREEN_HEIGHT - game->screen->line_height) / 2;
	if(game->screen->start_y <= 0)
		game->screen->start_y = 0;
	game->screen->end_y = (SCREEN_HEIGHT + game->screen->line_height) / 2;
	if(game->screen->end_y >= SCREEN_HEIGHT)
		game->screen->end_y = SCREEN_HEIGHT;
	intersection_point(game);
	find_texture_position_x(game);
	game->screen->texture_pos = (game->screen->start_y - SCREEN_HEIGHT / 2
			+ game->screen->line_height / 2) * game->screen->texture_step;
	draw_floor(game, x);
	draw_ceiling(game, x);
	draw_wall(game, x);
}
