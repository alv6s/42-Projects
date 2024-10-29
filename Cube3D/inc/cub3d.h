/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:24:24 by pevieira          #+#    #+#             */
/*   Updated: 2024/10/29 13:44:52 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

# define ERROR 0
# define SUCCESS 1

# define W_SPACES " \n\t\r\f\v"

# define MAP_FOUND 1

# define MAPFILE ".cub"
# define TEXTUREFILE ".xpm"

# define ERROR_NAME1 "Erro NAMECHECK"
# define ERROR_NAME2 "Erro NAMECHECK2"

# define ERROR_NAME3 "Erro FILE"

# define ERROR_INVALID "Erro Invalid"
# define ERROR_ARGS "Erro1"

# define ERROR_REPETED "Erro Repetead"
# define ERROR_OPEN	"Couldn't open texture file"

# define NO_CLEAN 0
# define CLEAN 1
# define VALID_CHARS " \n01NSEW"
# define FLOOR 0
# define CEILING 1
# define NORTH 2
# define SOUTH 3
# define EAST 4
# define WEST 5

typedef struct s_player //the player structure
{
 int  position_x; // player x position in pixels
 int  position_y; // player y position in pixels
 double angle; // player angle
 float fov_rd; // field of view in radians
 int  rot; // rotation flag
 int  l_r; // left right flag
 int  u_d; // up down flag
} t_player;

typedef struct s_ray //the ray structure
{
 double ray_ngl; // ray angle
 double distance; // distance to the wall
 int  flag;  // flag for the wall
} t_ray;

typedef struct s_map //the data structure
{
 char **map2d;
 char *t_map;
 char	*line;
 int  player_x;
 int  player_y;
 int  width_map;
 int  height_map;
 char *north;
 char *south;
 char *east;
 char *west;
 int	colors[2];
 
} t_map;

typedef struct s_game //the mlx structure
{
 t_map	*map; // the data structure
 t_player  *player; // the player structure
 t_ray   *ray; // the ray structure
} t_game;

int	init_game_data(t_game *cub3d, char *map_file);
int	file_parser(t_game *cub3d, char *map_file);
int	map_parser(t_game *cub3d, int fd);
int	validate_line(t_game *cub3d, char *line);
int	line_tokenizer(t_game *cub3d);
int	ft_isdigit_str(const char *str);
void	free_tokens(char **tokens);
int	assign_color(t_game *cub3d, int color, char *rgb_str);
int	parse_rgb(char *rgb_str, int *rgb, int i);
void	assign_texture(t_game *cub3d, int direction, int i);
int	texture_validation(t_game *cub3d, char *texture);
int	exit_error(t_game *cub3d, char *str, char *variable);
void	exit_clean(t_game *cub3d);
void	clean_map(t_map *map);
int	file_name_check(char *str, char *mode);

#endif
