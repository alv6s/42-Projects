/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:41:48 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/19 23:33:22 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <limits.h>
# include <fcntl.h>

# define TILE		20
# define ESC		65307
# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363

typedef struct s_data
{
	int		fd;
	int		rows;
	int		cols;
	
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x;
	int		y;
	int		counter;
	int		collectables;
	int		player_x;
	int		player_y;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*img;
	
	void	*mlx_ptr;
	void	*win_ptr;

}	t_game;


void	so_long();
void	init_mlx(t_game *game);
int		map_reading(t_game *game, char *file);
void	ft_map_check(t_game *game);
int		ft_check_characters(t_game *game);
int		ft_check_retangular(t_game *game);
int		ft_check_walls(t_game *game);
int		ft_check_path(t_game *game);
int		ft_flood_fill(t_game *game, char **map, int y, int x);

void	init_game(t_game *game);
int		check_argument(char *argument);
int		ft_keypress(int keycode, t_game *game);
int		ft_move_player(t_game *game, int x, int y);


int		ft_error_exit(t_game *game, char *msg, int fd);
void 	free_game(t_game *game);
void	free_array(char **map);

#endif