/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/10/23 16:09:45 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void free_game(t_game *game)
{
	if (game)
	{
		if (game->map.grid)
			free_array(game->map.grid)
		free_textures(game);
		if (game->mlx && game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}	
	}
}

int	exit(t_game *game,char *msg, int fd)
{
	if (fd == 2)
		ft_putendl_fd("Error", fd);
	ft_putendl_fd(msg, fd);
	free_game(t_game *game);
	if (fd == 2)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS)
}
