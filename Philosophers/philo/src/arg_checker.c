/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:48:43 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/04 18:55:27 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_nb(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	str_is_nb(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_nb(str[i]) == 0)
			return (0);
	}
	return (1);
}

int	arguments_are_nbs(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (str_is_nb(av[i]))
			;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + str[i] - 48;
			i++;
		}
		return (result * sign);
	}
	return (0);
}

bool	check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6 || !arguments_are_nbs(av))
	{
		error("Error: Wrong format.\nUsage:  \
        ./philo nb_philos dead_time eat_time sleep_time [nb_meals]", NULL);
		return (false);
	}
	else if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 1 || ft_atoi(av[3]) < 1 || \
		ft_atoi(av[4]) < 1 || (ac == 6 && ft_atoi(av[5]) < 0))
	{
		error("Error: Use positive numbers.", NULL);
		return (false);
	}
	else if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		error("Use valid inputs.", NULL);
		return (false);
	}
	return (true);
}
