


if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid;




Edge cases for map checking. 
hink of invalid permissions,
 a map with too few columns/rows,
  or even an empty line in the middle of the map.


  

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nYou Have Won, Congrats!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 13)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 0)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}
////////
int	keypress(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 13)
		works = ft_move_player(game, command);
	if (command == 1)
		works = keyboard_w_s(game, command);
	if (command == 0)
		works = keyboard_a_d(game, command);
	if (command == 2)
		works = keyboard_a_d(game, command);
	return (1);
}

int	ft_move_player(t_data *game, int x, int y)
{
	if (d->map.map[y][x] == '0' || d->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->spr.f_img, d->plr.p_c * SIZE, d->plr.p_r * SIZE);
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->spr.p_img, x * SIZE, y * SIZE);
		if (d->map.map[y][x] == 'C')
			d->plr.to_collect--;
		d->map.map[d->plr.p_r][d->plr.p_c] = '0';
		d->map.map[y][x] = '0';
		d->plr.p_c = x;
		d->plr.p_r = y;
		d->plr.n_moves++;
		return (1);
	}
	if (d->map.map[y][x] == 'E' && d->plr.to_collect == 0)
	{
		ft_printf("Moves: %i\n", d->plr.n_moves + 1);
		ft_printf("Congratulations, you finished the game!\n");
		ft_close_win(d);
	}
	if (to_print == 1)
		ft_printf("Moves: %i\n", data->plr.n_moves);
	return (0);
}