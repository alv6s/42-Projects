/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:41:48 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/19 14:21:05 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <limits.h>
# include <fcntl.h>

# define TILE		50
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


#endif