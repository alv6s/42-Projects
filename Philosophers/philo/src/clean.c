/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:01:09 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/04 18:50:52 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	clear_table(t_table	*table)
{
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}

void	ft_exit(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->finish_dinner);
	pthread_mutex_destroy(&table->waiting_start_simulation);
	pthread_mutex_destroy(&table->meal_time_and_quantity_checker);
	clear_table(table);
}

int	error(char *str, t_table *table)
{
	printf("%s\n", str);
	if (table)
		ft_exit(table);
	return (1);
}
