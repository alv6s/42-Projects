/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:31:00 by pevieira          #+#    #+#             */
/*   Updated: 2023/10/23 15:44:48 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char *av)
{
	if (ac != 2)
		ft_printerror();
	if (check_param(av[1]))
		ft_error(,2);
	so_long();
}

bool	check_param(char *param)
{
	int	i;

	i = 0;
	while (param[i])
		i++;
	if (param[i - 1] != 'r' || param[i - 2] != 'e' || param[i - 3] != 'b'
			|| param[i - 4] != '.')
		return (true);
	return (false);
}			