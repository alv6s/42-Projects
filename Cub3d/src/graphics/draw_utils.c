/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:53:22 by migupere          #+#    #+#             */
/*   Updated: 2024/11/04 15:43:18 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	my_pixel_get(t_render *texture, int x, int y)
{
	int	color;
	
	color = (*(unsigned int *)(texture->addr + (y * texture->line_len)
		+ (x * (texture->bpp / 8))));
	return (color);
}

void	my_pixel_put(t_render *texture, int x, int y, int color)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceiling(t_game *game, int x)
{
	int	y;
	int	ceiling_color;

	y = 0;
	ceiling_color = game->map->colors[CEILING];
	while (y < game->screen->start_y)
	{
		my_pixel_put(game->screen, x, y, ceiling_color);
		y++;
	}
}

void	draw_floor(t_game *game, int x)
{
	int	y;
	int	floor_color;

	y = game->screen->end_y;
	floor_color = game->map->colors[FLOOR];
	while (y < (int)SCREEN_HEIGHT)
	{
		my_pixel_put(game->screen, x, y, floor_color);
		y++;
	}
}

void	draw_wall(t_game *game, int x)
{
	int	y;
	int	text_y;
	int	color;

	y = game->screen->start_y;
	while (y < game->screen->end_y)
	{
		text_y = (int)game->screen->texture_pos & (TILE_SIZE - 1);
		game->screen->texture_pos += game->screen->texture_step;
		color = my_pixel_get(&game->render[game->screen->index], game->screen->texture_x, text_y);
		my_pixel_put(game->screen, x, y, color);
		y++;
	}
}
