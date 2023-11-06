void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);


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