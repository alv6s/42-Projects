/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pevieira <pevieira@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 10:42:40 by pevieira		  #+#	#+#			 */
/*   Updated: 2024/10/29 15:58:01 by pevieira		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/cub3d.h"

int	file_name_check(char *str, char *mode, t_game *cub3d)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str_len <= 4)
		return (exit_error(NULL, ERROR_NAME1, mode));
	else if (ft_strncmp(str + str_len - 4, mode, 4) != 0)
		return (exit_error(cub3d, ERROR_NAME2, mode));
	return (SUCCESS);
}

void	clean_map(t_game *cub3d)
{
	int	i;

	i = -1;
	if (cub3d->map->map2d != NULL)
	{
		while (cub3d->map->map2d[++i] != NULL)
			free(cub3d->map->map2d[i]);
		free(cub3d->map->map2d);
	}
	if(cub3d->map->line && cub3d->map->line[0])
		free(cub3d->map->line);
	if (cub3d->map->north)
		free(cub3d->map->north);
	if (cub3d->map->east)
		free(cub3d->map->east);
	if (cub3d->map->south)
		free(cub3d->map->south);
	if (cub3d->map->west != NULL)
		free(cub3d->map->west);
}

void	exit_clean(t_game *cub3d)
{
	printf("\n************* CLEANING *************\n");
	if (cub3d->player)
	{
		free(cub3d->player);
		cub3d->player = NULL;
	}

	if (cub3d->map->t_map)
		free(cub3d->map->t_map);
	printf("************************************");
	clean_map(cub3d);
	if (cub3d)
	{
		free(cub3d->map);
		free(cub3d);
		cub3d = NULL;
	}
	printf("\n************ CLEAN DONE ************\n");
}

int	exit_error(t_game *cub3d, char *str, char *variable)
{
	ft_printf(str, variable);
	if (cub3d != NULL)
		exit_clean(cub3d);
	return (ERROR);
}

char	*trim_newline(char *str) 
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len] == '\n')
		str[len] = '\0';
	return (str);
}

int	texture_validation(t_game *cub3d, char *texture)
{
	int	fd;

	texture = ft_strtrim(texture, W_SPACES);
	if (file_name_check(texture, TEXTUREFILE, cub3d))
	{
		fd = open(texture, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			return (exit_error(cub3d, ERROR_OPEN, NULL));
		}
		free(texture);
		close(fd);
		return (SUCCESS);
	}
	free(texture);
	return (ERROR);
}

int	assign_texture(t_game *cub3d, int direction, int i)
{
	while (cub3d->map->line[i] && ft_strchr(W_SPACES, cub3d->map->line[i]))
		i++;
	if (texture_validation(cub3d, cub3d->map->line + i))
	{
		if (direction == NORTH && !cub3d->map->north)
			cub3d->map->north = ft_strdup(cub3d->map->line + i);
		else if (direction == SOUTH && !cub3d->map->south)
			cub3d->map->south = ft_strdup(cub3d->map->line + i);
		else if (direction == EAST && !cub3d->map->east)
			cub3d->map->east = ft_strdup(cub3d->map->line + i);
		else if (direction == WEST && !cub3d->map->west)
			cub3d->map->west = ft_strdup(cub3d->map->line + i);
		else
			return(exit_error(cub3d, ERROR_REPETED, NULL));
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int	parse_rgb(char *rgb_str, int *rgb, int i, t_game *cub3d)
{
	char	**tokens;
	char	*old_token;

	tokens = ft_split(rgb_str, ',');
	if (!tokens)
		return (exit_error(cub3d, "Erro colocar_ missing color parameter", NULL));
	while (tokens[i] != NULL)
		i++;
	if (i != 3)
	{
		free_tokens(tokens);
		return (exit_error(cub3d, "Erro colocar_ missing color parameter", NULL));
	}
	i = -1;
	while (++i < 3)
	{
		old_token = tokens[i];
		tokens[i] = ft_strtrim(tokens[i], W_SPACES);
		free(old_token);
		if (!ft_isdigit_str(tokens[i]))
		{
			free_tokens(tokens);
			return (exit_error(cub3d, "ERRO POR COLOCAR / COR INVALIDA", NULL));
		}
		if (!tokens[i] || !ft_isdigit_str(tokens[i]) || \
			(rgb[i] = ft_atoi(tokens[i])) < 0 || rgb[i] > 255)
		{
			free_tokens(tokens);
			return (exit_error(cub3d, "ERRO POR COLOCAR / COR INVALIDA", NULL));
		}
	}
	free_tokens(tokens);
	return (SUCCESS);
}

int	assign_color(t_game *cub3d, int color, char *rgb_str)
{
	int		rgb[3];

	if (cub3d->map->colors[color] != -1)
		return (exit_error(cub3d, "Color duplicated", NULL));
	if (!parse_rgb(rgb_str, rgb, 0, cub3d))
		return (ERROR);
	cub3d->map->colors[color] = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (true);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

int	ft_isdigit_str(const char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	line_tokenizer(t_game *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map->line[i] && ft_strchr(W_SPACES, cub3d->map->line[i]))
		i++;
	if (ft_strncmp(cub3d->map->line + i, "NO", 2) == 0)
		return (assign_texture(cub3d, NORTH, i + 2));
	else if (ft_strncmp(cub3d->map->line + i, "SO", 2) == 0)
		return (assign_texture(cub3d, SOUTH, i + 2));
	else if (ft_strncmp(cub3d->map->line + i, "EA", 2) == 0)
		return (assign_texture(cub3d, EAST, i + 2));
	else if (ft_strncmp(cub3d->map->line + i, "WE", 2) == 0)
		return (assign_texture(cub3d, WEST, i + 2));
	else if (ft_strncmp(cub3d->map->line + i, "F", 1) == 0)
		return (assign_color(cub3d, FLOOR, cub3d->map->line + i + 1));
	else if (ft_strncmp(cub3d->map->line + i, "C", 1) == 0)
		return (assign_color(cub3d, CEILING, cub3d->map->line + i + 1));
	else if (cub3d->map->line[i] == '0' || cub3d->map->line[i] == '1')
		return (MAP_FOUND);
	else if (cub3d->map->line[i] != '\0')
		return(exit_error(cub3d, ERROR_INVALID, NULL));
	return (SUCCESS);
}

int	validate_line(t_game *cub3d, char *line)
{
	int	i;

	i = -1;
	while (line && ft_strchr(" \t", line[++i]))
		;
	if (!line || !line[i] || line[i] == '\n')
		return (BREAK);
	i = -1;
	while (line[++i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			return (exit_error(cub3d, "Map has invalid characters", NULL));
		if (ft_strchr(SPAWN_DIRECTIONS, line[i]))
		{
			if (cub3d->player->direction == 0)
				cub3d->player->direction = line[i];
			else
				return(exit_error(cub3d, ERROR_MULTIPLE_SPAWN, NULL));
		}
	}
	return (SUCCESS);
}

int	player_set(t_game	*cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (cub3d->map->map2d[++i])
	{
		j = -1;
		while (cub3d->map->map2d[i][++j])
		{
			if (cub3d->map->map2d[i][j] == cub3d->player->direction)
			{
				cub3d->player->position_y = i;
				cub3d->player->position_x = j;
				cub3d->map->map2d[i][j] = '0';
				return (SUCCESS);
			}
		}
	}
	return (exit_error(cub3d, ERROR_NO_SPAWN, NULL));
}

int	map_parser(t_game *cub3d, int fd)
{
	char	*tmp;
	int		flag;

	while (1)
	{
		flag = validate_line(cub3d, cub3d->map->line);
		if (flag == ERROR)
			return (ERROR);
		else if (flag == BREAK)
			break ;
		if (cub3d->map->t_map[0] != '\0')
		{
			tmp = ft_strjoin(cub3d->map->t_map, "X");
			cub3d->map->t_map = tmp;
		}
		tmp = ft_strjoin(cub3d->map->t_map, cub3d->map->line);
		cub3d->map->t_map = ft_strdup(tmp);
		free(tmp);
		free(cub3d->map->line);
		cub3d->map->line = get_next_line(fd);
	}
	cub3d->map->map_end = true;
	while (cub3d->map->line)
	{
		if (validate_line(cub3d, cub3d->map->line) == SUCCESS)
			return (exit_error(cub3d, "Unexpected content after map", NULL));
		free(cub3d->map->line);
		cub3d->map->line = get_next_line(fd);
	}
	cub3d->map->map2d = ft_split(cub3d->map->t_map, 'X');
	if (player_set(cub3d))
		return (SUCCESS);
	return (ERROR);
}

int	info_checker(t_game	*cub3d)
{
	if (!cub3d->map->north || !cub3d->map->south || !cub3d->map->east || \
		!cub3d->map->west || cub3d->map->colors[FLOOR] == -1 || \
		cub3d->map->colors[CEILING] == -1)
		return (exit_error(cub3d, "Missing information", NULL));
	return (SUCCESS);
}

int	file_parser(t_game *cub3d, char *map_file)
{
	int	fd;
	int	flag;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (exit_error(cub3d, ERROR_NAME3, NULL));
	while (1)
	{
		cub3d->map->line = get_next_line(fd);
		if (!cub3d->map->line)
			return (EMPTY_INCOMPLETE);
		flag = line_tokenizer(cub3d);
		if (flag == MAP_FOUND)
		{
			if (!info_checker(cub3d) || !map_parser(cub3d, fd))
				return (ERROR);
			break ;
		}
		else if (flag == ERROR)
			return (ERROR);
		free(cub3d->map->line);
	}
	return (SUCCESS);
}

int	map_checker(t_game *cub3d)
{
	int	x;
	int	y;

	y = -1;
	while (cub3d->map->map2d[++y])
	{
		x = -1;
		while (cub3d->map->map2d[y][++x])
		{
			if (ft_strchr("0", cub3d->map->map2d[y][x]))
			{
				if (x == 0 || y == 0 || !cub3d->map->map2d[y + 1] || \
					(cub3d->map->map2d[y][x + 1] == '\0') ||
					x >= (int)ft_strlen(cub3d->map->map2d[y + 1]) ||
					x >= (int)ft_strlen(cub3d->map->map2d[y - 1]) ||
					cub3d->map->map2d[y][x + 1] == ' ' ||
					cub3d->map->map2d[y][x - 1] == ' ' ||
					cub3d->map->map2d[y + 1][x] == ' ' ||
					cub3d->map->map2d[y - 1][x] == ' ')
					return (exit_error(cub3d, "Map is not closed", NULL));
			}
		}
	}
	return (SUCCESS);
}

void	analyse_error(t_game *cub3d)
{
	if (cub3d->map->north == NULL && cub3d->map->south == NULL && \
		cub3d->map->east == NULL && cub3d->map->west == NULL && \
		cub3d->map->colors[FLOOR] == -1 && cub3d->map->colors[CEILING] == -1 && \
		cub3d->map->line == NULL)
		exit_error(cub3d, "Map is empty", NULL);
	else if (cub3d->map->north != NULL && cub3d->map->south != NULL && \
		cub3d->map->east != NULL && cub3d->map->west != NULL && \
		cub3d->map->colors[FLOOR] >= 0 && cub3d->map->colors[CEILING] >= 0 && \
		cub3d->map->line == NULL)
		exit_error(cub3d, "Map not found", NULL);
	else
		info_checker(cub3d);
}

int	init_game_data(t_game *cub3d, char *map_file)
{
	int	flag;

	cub3d->player = (t_player *)calloc(1, sizeof(t_player));
	if (!cub3d->player)
		return (ERROR);
	cub3d->map = (t_map *)calloc(1, sizeof(t_map));
	cub3d->map->line = NULL; 
	cub3d->map->t_map = (char *)calloc(1, sizeof(char)); 
	cub3d->map->colors[FLOOR] = -1;
	cub3d->map->colors[CEILING] = -1;
	flag = file_parser(cub3d, map_file);
	if (flag == SUCCESS)
	{
		if (map_checker(cub3d))
			return (SUCCESS);
	}
	else if (flag == EMPTY_INCOMPLETE)
		analyse_error(cub3d);
	return (ERROR);
}

void	game_rendering(t_game *cub3d)
{
	int	i;

	i = 0;
	printf("\n************* GAME RENDERING *************\n\n");
	while (cub3d->map->map2d[i] != NULL)
	{
		printf("%s\n", cub3d->map->map2d[i]);
		i++;
	}
	printf("\nNorth: %s\n", cub3d->map->north);
	printf("South: %s\n", cub3d->map->south);
	printf("East: %s\n", cub3d->map->east);
	printf("West: %s\n", cub3d->map->west);

	printf("\nFloor: %d\n", cub3d->map->colors[FLOOR]);
	printf("Ceiling: %d\n", cub3d->map->colors[CEILING]);

	printf("\nPlayer direction: %c\n", cub3d->player->direction);
	
	printf("Player position x: %d\n", cub3d->player->position_x);
	printf("Player position y: %d\n", cub3d->player->position_y);

	init_mlx_and_textures(cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, &key_press, cub3d);
	mlx_hook(cub3d->win, 3, 1L << 1, &key_release, cub3d);
	mlx_hook(cub3d->win, 17, 1L << 0, &end_game, cub3d);
	define_initial_plane(cub3d);
	mlx_loop_hook(cub3d->mlx, &draw_rays, cub3d);
	mlx_loop(cub3d->mlx);

}

void init_structs (t_game *game)
{
	*game = (t_game){0};
	game->map = malloc(sizeof(t_map));
	ft_memset(game->map, 0, sizeof(t_map));
	game->player = (t_player *)malloc(sizeof(t_player));
	ft_memset(game->player, 0, sizeof(t_player));
	
	//game->ray = (t_dda *)malloc(sizeof(t_dda));
	ft_memset(&game->ray, 0, sizeof(t_dda));
	game->screen = (t_render *)malloc(sizeof(t_render));
	ft_memset(game->texture, 0, sizeof(t_render));
	game->ray.hit = false;
}

int	main(int ac, char **av)
{
	t_game	*cub3d;

	if (ac == 2)
	{
		if (file_name_check(av[1], MAPFILE, NULL))
		{
			cub3d = ft_calloc(1, sizeof(t_game));
			ft_memset(cub3d, 0, sizeof(t_game));
			init_structs(cub3d);
			if (init_game_data(cub3d, av[1]))
			{
				game_rendering(cub3d);
				exit_clean(cub3d);
				return (EXIT_SUCCESS);
			}
		}
	}
	else
		return (exit_error(NULL, ERROR_ARGS, NULL));
	return (EXIT_FAILURE);
}
