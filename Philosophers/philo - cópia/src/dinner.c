/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:15 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/04 18:15:24 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->first_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->second_fork]);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->first_fork]);
		print_message("has taken a fork", philo);
		pthread_mutex_lock(&philo->table->forks[philo->second_fork]);
		print_message("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->second_fork]);
		print_message("has taken a fork", philo);
		pthread_mutex_lock(&philo->table->forks[philo->first_fork]);
		print_message("has taken a fork", philo);
	}
}

void	dinner_for_one(t_table *table)
{
	print_message("has taken a fork", &table->philos[0]);
	ft_usleep(&table->philos[0], table->death_time);
	finish_simulation(&table->philos[0], true);
}

void	dinner_is_served(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->table->meal_time_and_quantity_checker);
	philo->last_meal = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->table->meal_time_and_quantity_checker);
	print_message("is eating", philo);
	ft_usleep(philo, philo->table->eat_time);
	drop_forks(philo);
}
