/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:31:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/11/04 19:11:20 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	so_long()
{
	t_game	*game;

	ft_bzero(game);
	init_mlx(t_game *game);
}

int	main(int ac, char *av)
{
	if (ac != 2)
		ft_error_exit((void), "Please use just 1 argument.\n", 2);

	if (check_argument(av[1]))
		ft_error_exit((void), "The map needs to be a ".ber" file.\n", 2);
	so_long();
}

bool	check_argument(char *argument)
{
	int	i;

	i = ft_strlen(argument);
	if (argument[i - 1] != 'r' || argument[i - 2] != 'e' || argument[i - 3] != 'b'
			|| argument[i - 4] != '.')
		return (true);
	return (false);
}			