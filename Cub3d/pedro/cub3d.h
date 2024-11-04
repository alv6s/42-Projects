/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:24:24 by pevieira          #+#    #+#             */
/*   Updated: 2024/11/04 15:31:10 by migupere         ###   ########.fr       */
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

typedef struct s_player
{
 int  position_x;
 int  position_y;
 char direction;
} t_player;

typedef struct s_map
{
 char **map2d;
 char *t_map;
 char	*line;
 char *north;
 char *south;
 char *east;
 char *west;
 int	colors[2];
 bool map_end;
 
} t_map;

typedef struct s_game
{
 t_map	*map;
 t_player  *player;
} t_game;

int	init_game_data(t_game *cub3d, char *map_file);
int	file_parser(t_game *cub3d, char *map_file);
int	map_parser(t_game *cub3d, int fd);
int	validate_line(t_game *cub3d, char *line);
int	line_tokenizer(t_game *cub3d);
int	ft_isdigit_str(const char *str);
void	free_tokens(char **tokens);
int	assign_color(t_game *cub3d, int color, char *rgb_str);
int	parse_rgb(char *rgb_str, int *rgb, int i, t_game *cub3d);
int	assign_texture(t_game *cub3d, int direction, int i);
int	texture_validation(t_game *cub3d, char *texture);
int	exit_error(t_game *cub3d, char *str, char *variable);
void	exit_clean(t_game *cub3d);
void	clean_map(t_game *cub3d);
int	file_name_check(char *str, char *mode, t_game *cub3d);

#endif
