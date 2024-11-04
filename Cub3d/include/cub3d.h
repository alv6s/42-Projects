/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:58:16 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/04 16:06:41 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <math.h>
# include <errno.h>
# include <stdint.h>

# define BUFF 50
# define NBR_TEXTURES 4
# define DIRECTIONS "NO,SO,EA,WE"
# define COLOR_PLACE "F ,C "
# define W 119
# define A 97
# define S 115
# define D 100
# define P 112
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define TILE_SIZE 64
# define PI 3.141592653589793
// # define NO_TEXTURE 0
// # define SO_TEXTURE 1
// # define WE_TEXTURE 2
// # define EA_TEXTURE 3
# define SPEED 0.1
# define ERROR 0
# define SUCCESS 1
# define CONTINUE 2
# define BREAK 2
# define EMPTY_INCOMPLETE 3
# define VALID 1

# define W_SPACES " \n\t\r\f\v"

# define MAP_FOUND 2

# define MAPFILE ".cub"
# define TEXTUREFILE ".xpm"

# define ERROR_NAME1 "Erro NAMECHECK"
# define ERROR_NAME2 "Erro NAMECHECK2"

# define ERROR_NAME3 "Erro FILE"

# define ERROR_INVALID "Erro Invalid"
# define ERROR_ARGS "Erro1"

# define ERROR_REPETED "Erro Repetead"
# define ERROR_OPEN	"Couldn't open texture file"

# define ERROR_MULTIPLE_SPAWN "Multiple spawn points"
# define ERROR_NO_SPAWN "No spawn point"

# define NO_CLEAN 0
# define CLEAN 1
# define VALID_CHARS " \t\n01NSEW"
# define SPAWN_DIRECTIONS "NSEW"

# define FLOOR 0
# define CEILING 1
# define NORTH 2
# define SOUTH 3
# define EAST 4
# define WEST 5

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;


typedef struct s_dda
{
	double		camera_x;
	t_coord		ray_dir;
	t_coord		delta_dist;
	t_coord		side_dist;
	t_coord		map_pos;
	t_coord		step;
	bool		hit;
	int			side;
	double		perp_wall_dist;
}	t_dda;

typedef struct s_player
{
	char		fov; // field of view
	t_vector	dir;
	t_vector	plane;
	double		move_speed;
	double		rot_speed;
	int			img_index;
	double		hit_dist;
	double		hit_x;
	int			pitch;
	int			init_pos_x;
	int			init_pos_y;
	t_vector	pos;


	int  position_x;
 	int  position_y;
	char direction;
}	t_player;

typedef struct s_map
{
	char	**map2d;
	char	*t_map;
	char *north;
 	char *south;
 	char *east;
 	char *west;
	char	*line;
	// int		n_lines;
	// int		width;
	// int		f_color;
	// int		c_color;
	int		colors[2];
	bool	map_end;
}	t_map;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	esc;
	int	left;
	int	right;
}	t_keys;

typedef struct s_render
{
	int		start_y;
	int		end_y;
	double	texture_step;
	int		index;
	double	texture_pos;
	int 	line_height;
	void	*img;
	int		width;
	int		height;
	double	point_x;
	int		texture_x;
	char	*addr;
	int		line_len;
	int		bpp;
	int		endian;
	t_map	*map;
}	t_render;

typedef struct s_game
{
	char		*file;
	t_map		*map;
	t_player	*player;
	t_keys		key;
	t_render	render[NBR_TEXTURES];
	t_render	*screen;
	char		*texture[NBR_TEXTURES];
	void		*mlx;
	void		*win;
	t_dda		ray;
}	t_game;

void	draw_walls_and_background(t_game *game, int x);
int		draw_rays(t_game *game);
void	init_mlx_and_textures(t_game *game);
void	draw_wall(t_game *game, int x);
void	draw_floor(t_game *game, int x);
void	draw_ceiling(t_game *game, int x);
t_vector	create_vector(float x, float y);
void	setup(t_game *game);
t_vector	rotate_vector(t_vector v, float angle);
void	load_textures(t_game *game);
int	my_pixel_get(t_render *texture, int x, int y);
void	my_pixel_put(t_render *texture, int x, int y, int color);
void	compute_new_player_position(t_game *game, double *new_x, double *new_y);
bool	is_valid_move(t_game *game, double new_x, double new_y);

int		end_game(t_game *game);
void	ft_perror(char *msg, t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);


int		init_game_data(t_game *cub3d, char *map_file);
int		file_parser(t_game *cub3d, char *map_file);
int		map_parser(t_game *cub3d, int fd);
int		validate_line(t_game *cub3d, char *line);
int		line_tokenizer(t_game *cub3d);
int		ft_isdigit_str(const char *str);
void	free_tokens(char **tokens);
int		assign_color(t_game *cub3d, int color, char *rgb_str);
int		parse_rgb(char *rgb_str, int *rgb, int i, t_game *cub3d);
int		assign_texture(t_game *cub3d, int direction, int i);
int		texture_validation(t_game *cub3d, char *texture);
int		exit_error(t_game *cub3d, char *str, char *variable);
void	exit_clean(t_game *cub3d);
void	clean_map(t_game *cub3d);
int		file_name_check(char *str, char *mode, t_game *cub3d);
void	define_initial_plane(t_game *game);

#endif
