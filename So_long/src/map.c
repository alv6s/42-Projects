https://github.com/gemartin99/So_long/tree/master/so_long/src

https://reactive.so/post/42-a-comprehensive-guide-to-so_long

https://harm-smits.github.io/42docs/libs/minilibx/hooks.html

https://cdn.intra.42.fr/pdf/pdf/105166/en.subject.pdf

https://github.com/LuisBalsa/so_long

https://github.com/someoneisanna/42-so_long


static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}





void	ft_map_check(t_data *data);
int		ft_check_characters(t_data *data);
int		ft_check_retangular(t_data *data);
int		ft_check_walls(t_data *data);
int		ft_check_path(t_data *data);

// check if the map is valid according to the rules
void	ft_map_check(t_data *data)
{
	if (data->map.n_rows < 3 || data->map.n_columns < 5)
		ft_perror("Error\nInvalid map - map is too small\n", data);
	if (ft_check_characters(data) == 0)
		ft_perror("Error\nInvalid map - wrong number of characters\n", data);
	if (ft_check_retangular(data) == 0)
		ft_perror("Error\nInvalid map - map is not retangular\n", data);
	if (ft_check_walls(data) == 0)
		ft_perror("Error\nInvalid map - map is not surrounded by walls\n", data);
	if (ft_check_path(data) == 0)
		ft_perror("Error\nInvalid map - map has no valid path\n", data);
}

// check if the number of characters is valid and if there are
// only 01CEP characters
int	ft_check_characters(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		d->j = 0;
		while (d->j < d->map.n_columns)
		{
			if (d->map.map[d->i][d->j] == 'C')
				d->map.n_collectibles++;
			else if (d->map.map[d->i][d->j] == 'E')
				d->map.n_exits++;
			else if (d->map.map[d->i][d->j] == 'P')
			{
				d->map.n_players++;
				d->plr.p_r = d->i;
				d->plr.p_c = d->j;
			}
			else if (ft_strchr("01CEP", d->map.map[d->i][d->j]) == 0)
				ft_perror("Error\nInvalid map - wrong character was found\n", d);
			d->j++;
		}
		d->i++;
	}
	return (d->map.n_collectibles >= 1 && d->map.n_exits == 1
		&& d->map.n_players == 1);
}

// check if the map is retangular (all lines have the same number of columns)
int	ft_check_retangular(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		if (ft_strlen(d->map.map[d->i]) != d->map.n_columns)
			return (0);
		d->i++;
	}
	return (1);
}

// check if the map is surrounded by walls (all lines start and end with 1)
int	ft_check_walls(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		if (d->map.map[d->i][0] != '1'
				|| d->map.map[d->i][d->map.n_columns - 1] != '1')
			return (0);
		d->i++;
	}
	d->i = 0;
	while (d->i < d->map.n_columns)
	{
		if (d->map.map[0][d->i] != '1'
				|| d->map.map[d->map.n_rows - 1][d->i] != '1')
			return (0);
		d->i++;
	}
	return (1);
}

// check if the map has a valid path (all 0 are connected to the player)
int	ft_check_path(t_data *d)
{
	int		e;
	char	**map_cpy;

	d->i = 0;
	e = 0;
	map_cpy = ft_calloc(d->map.n_rows + 1, sizeof(char *));
	if (!map_cpy)
		ft_perror("Error\nMalloc failed\n", d);
	while (d->i < d->map.n_rows)
	{
		map_cpy[d->i] = ft_strdup(d->map.map[d->i]);
		{
			if (!d->map.map[d->i])
			{
				ft_free_map(map_cpy);
				ft_perror("Error\nMalloc failed\n", d);
			}
		}
		d->i++;
	}
	e = ft_flood_fill(d, map_cpy, d->plr.p_r, d->plr.p_c);
	ft_free_map(map_cpy);
	return (e);
}



// recursive function to check if the map is valid
int	ft_flood_fill(t_data *d, char **map, int x, int y)
{
	int			n_collectibles;
	static int	c;
	static int	e;

	n_collectibles = d->map.n_collectibles;
	if (map[y][x] == '1')
		return (0);
	else if (map[y][x] == 'C')
		c += 1;
	else if (map[y][x] == 'E')
	{
		e = 1;
		return (0);
	}
	map[y][x] = '1';
	ft_flood_fill(d, map, x + 1, y);
	ft_flood_fill(d, map, x - 1, y);
	ft_flood_fill(d, map, x, y + 1);
	ft_flood_fill(d, map, x, y - 1);
	if (c == n_collectibles && e == 1)
		return (1);
	else
		return (0);
}