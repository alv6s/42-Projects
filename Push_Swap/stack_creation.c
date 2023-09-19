/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:56:54 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/19 15:58:34 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		signal;
	int		i;

	result = 0;
	signal = 1;
	i = 0;
	while ((str[i] >= 9 && str[i]<= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * signal);
}

void	stack_creator(t_stack **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_nbr_validation(av[i]))
			free_and_print_error(a);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_and_print_error(a);
		if (check_existing_repetitions(*a, (int)nbr))
			free_and_print_error(a);
		append_node(a, (int)nbr);
		++i;
	}
}
