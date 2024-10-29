/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:42:40 by pevieira          #+#    #+#             */
/*   Updated: 2024/10/29 13:51:26 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d.h"

int	file_name_check(char *str, char *mode)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str_len <= 4)
		return (exit_error(NULL, ERROR_NAME1, mode));
	else if (ft_strncmp(str + str_len - 4, mode, 4) != 0)
		return (exit_error(NULL, ERROR_NAME2, mode));
	return (SUCCESS);
}

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map2d)
	{
		while (map->map2d[++i] != NULL)
			free(map->map2d[i]);
		free(map->map2d);
	}
	else if(map->line)
		free(map->line);
	else if (map->north)
		free(map->north);
	else if (map->east)
		free(map->east);
	else if (map->south)
		free(map->south);
	else if (map->west)
		free(map->west);
	free(map);
}

void	exit_clean(t_game *cub3d)
{
	if (cub3d->map)
		clean_map(cub3d->map);
	if (cub3d->player)
		free(cub3d->player);
	//if (cub3d->mlx_p)
	//	mlx_terminate(cub3d->mlx_p);
	if (cub3d->ray)
		free(cub3d->ray);
	//if (cub3d->img)
	//	mlx_delete_image(cub3d->mlx_p, cub3d->img);
}

int	exit_error(t_game *cub3d, char *str, char *variable)
{
	ft_printf(str, variable);
	if (cub3d != NULL)
		exit_clean(cub3d);
	return (EXIT_FAILURE);
}
char *trim_newline(char *str) {
    size_t len = ft_strlen(str);
    if (len > 0 && str[len] == '\n')
        str[len] = '\0';
	return (str);
}
int	texture_validation(t_game *cub3d, char *texture)
{
	int	fd;

	texture = trim_newline(texture);
	if (file_name_check(texture, TEXTUREFILE))
	{
		fd = open(texture, O_RDONLY);
		if (fd < 0)
		{
			perror("Erro ao abrir o arquivo");
			close(fd);
			return (exit_error(cub3d, ERROR_OPEN, NULL));
		}
		close(fd);
	}
	return (SUCCESS);
}

void	assign_texture(t_game *cub3d, int direction, int i)
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
			exit_error(cub3d, ERROR_REPETED, NULL);
	}
}

int	parse_rgb(char *rgb_str, int *rgb, int i)
{
	char	**tokens;

	tokens = ft_split(rgb_str, ',');
	if (!tokens)
		return (0);
	while (tokens[i] != NULL)
		i++;
	if (i != 3)
	{
		free_tokens(tokens);
		return (0);
	}
	i = -1;
	while (++i < 3)
	{
		tokens[i] = ft_strtrim(tokens[i], W_SPACES);
		if (!tokens[i] || !ft_isdigit_str(tokens[i]) || \
			(rgb[i] = ft_atoi(tokens[i])) < 0 || rgb[i] > 255)
		{
			free_tokens(tokens);
			return (exit_error(NULL, "ERRO POR COLOCAR / COR INVALIDA", NULL));
		}
	}
	free_tokens(tokens);
	return (1);
}

int	assign_color(t_game *cub3d, int color, char *rgb_str)
{
	int		rgb[3];

	if (cub3d->map->colors[color])
		return (exit_error(cub3d, "Color duplicated", NULL));
	if (!parse_rgb(rgb_str, rgb, 0))
		return (exit_error(cub3d, "Invalid RGB format", NULL));
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
		assign_texture(cub3d, NORTH, i + 2);
	else if (ft_strncmp(cub3d->map->line + i, "SO", 2) == 0)
		assign_texture(cub3d, SOUTH, i + 2);
	else if (ft_strncmp(cub3d->map->line + i, "EA", 2) == 0)
		assign_texture(cub3d, EAST, i + 2);
	else if (ft_strncmp(cub3d->map->line + i, "WE", 2) == 0)
		assign_texture(cub3d, WEST, i + 2);
	else if (ft_strncmp(cub3d->map->line + i, "F", 1) == 0)
		assign_color(cub3d, FLOOR, cub3d->map->line + i + 1);
	else if (ft_strncmp(cub3d->map->line + i, "C", 1) == 0)
		assign_color(cub3d, CEILING, cub3d->map->line + i + 1);
	else if (cub3d->map->line[i] == '0' || cub3d->map->line[i] == '1')
		return (MAP_FOUND);
	else if (cub3d->map->line[i] != '\0')
		exit_error(cub3d, ERROR_INVALID, NULL);
	return (0);
}
int	validate_line(t_game *cub3d, char *line)
{
	int	i;

	i = -1;
	while (line && ft_strchr(" \t", line[++i]))
		printf("1-o Caracter é: %c\n", line[i]);
		;
	if (!line || !line[i] || line[i] == '\n')
	{
		printf("2-o Caracter é: %c\n", line[i]);
		return (false);
	}
	i = -1;
	while (line[++i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			return (exit_error(cub3d, "Map has invalid characters", NULL));
	}
	printf("Passou aqui\n");
	return (SUCCESS);
}

int	map_parser(t_game *cub3d, int fd)
{
	char *tmp;

	tmp = NULL;
	while (validate_line(cub3d, cub3d->map->line))
	{
		 if (cub3d->map->t_map[0] != '\0')
        {
			printf("AAAAA\n");
            tmp = ft_strjoin(cub3d->map->t_map, "\n"); // Adiciona quebra de linha
            cub3d->map->t_map = tmp;
        }
		printf("a line é: %s'", cub3d->map->line);
		tmp= ft_strjoin(cub3d->map->t_map, cub3d->map->line);
		printf("tmp é: %s\n", tmp);
		cub3d->map->t_map = ft_strdup(tmp);
		free(tmp);
		free(cub3d->map->line);
		cub3d->map->line= NULL;
		cub3d->map->line = get_next_line(fd);
	}
	while (cub3d->map->line)
	{
		printf("socrro\n");
		if (validate_line(cub3d, cub3d->map->line))
		{
			free(cub3d->map->line);
			return (exit_error(cub3d, "Unexpected content after map", NULL));
		}
		free(cub3d->map->line);
		cub3d->map->line = get_next_line(fd);
	}
	cub3d->map->map2d = ft_split(cub3d->map->t_map, '\n');
	 for (int i = 0; cub3d->map->map2d[i] != NULL; i++) // Percorre cada linha até encontrar NULL
    {
        printf("Linha %d: %s\n", i, cub3d->map->map2d[i]); // Imprime cada linha do mapa2d
    }

	free(cub3d->map->t_map);
	cub3d->map->t_map = NULL;
	return (SUCCESS);
}

int	file_parser(t_game *cub3d, char *map_file)
{
	int	fd;

	printf("B\n");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (exit_error(cub3d, ERROR_NAME3, NULL));
	printf("C\n");
	while (1)
	{
		printf("D\n");
		cub3d->map->line = get_next_line(fd);
		if (!cub3d->map->line)
			return (ERROR);
		printf("E\n");
		if (line_tokenizer(cub3d) == MAP_FOUND)
		{
			printf("F\n");
			if (!map_parser(cub3d, fd))
				return (ERROR);
			break ;
		}
		free(cub3d->map->line);
	}
	return (SUCCESS);
}

int	init_game_data(t_game *cub3d, char *map_file)
{
	printf("AAAII\n");
	cub3d->player = (t_player *)calloc(1, sizeof(t_player));
	if (!cub3d->player)
		return (ERROR);

	cub3d->ray = (t_ray *)calloc(1, sizeof(t_ray));
	if (!cub3d->ray)
	{
		free(cub3d->player);
		return (ERROR);
	}
	cub3d->ray->distance = -1;
	printf("a\n");
	cub3d->map = (t_map *)calloc(1, sizeof(t_map));
	cub3d->map->line = (char *)calloc(1, sizeof(char)); 
	cub3d->map->t_map = (char *)calloc(1, sizeof(char)); 
	if (!cub3d->map)
	{
		free(cub3d->player);
		free(cub3d->ray);
		return (ERROR);
	}
	if (file_parser(cub3d, map_file))
		//if (map_checker(cub3d) && player_set(cub3d, -1, -1))   FALTA ISSO
		return (SUCCESS);
	return (ERROR);
}

int	main(int ac, char **av)
{
	t_game	*cub3d;

	if (ac == 2)
	{
		printf("1\n");
		if (file_name_check(av[1], MAPFILE))
		{
			printf("2\n");
			cub3d = ft_calloc(1, sizeof(t_game));
			ft_memset(cub3d, 0, sizeof(t_game));
			printf("3\n");
			if (init_game_data(cub3d, av[1]))
			{
				printf("4\n");
				//game_rendering(cub3d);
				exit_clean(cub3d);
				return (EXIT_SUCCESS);
			}
		}
	}
	else
	{
	printf("5\n");
		return (exit_error(NULL, ERROR_ARGS, NULL));
	}
	return (EXIT_FAILURE);
}
