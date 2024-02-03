/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:15 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/03 11:07:46 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->table->forks[philo->first_fork]);
    pthread_mutex_unlock(&philo->table->forks[philo->second_fork]);

    print_message("is sleeping", philo);
    ft_usleep(philo->table->sleep_time);
}

void take_forks(t_philo *philo)
{
    //fazer inversao aqui
    pthread_mutex_lock(&philo->table->forks[philo->first_fork]);
    print_message("has taken a fork", philo);

    pthread_mutex_lock(&philo->table->forks[philo->second_fork]);
    print_message("has taken a fork", philo);
}

int eat(t_philo *philo)
{
    if (philo->table->nb_philo == 1)
    {
        print_message("has taken a fork", philo);
        ft_usleep(philo->table->eat_time);
        pthread_mutex_lock(&philo->table->lock);
        philo->table->end_simulation = true; 
        pthread_mutex_unlock(&philo->table->lock);
        return (1);
    }
    take_forks(philo);
    pthread_mutex_lock(&philo->lock);
    philo->eating = true;
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->lock);
    pthread_mutex_lock(&philo->table->lock);
    philo->time_left = philo->last_meal + philo->table->death_time;
    pthread_mutex_unlock(&philo->table->lock);
    print_message("is eating", philo);
    ft_usleep(philo->table->eat_time);
    pthread_mutex_lock(&philo->lock);
    philo->eating = false;
    philo->meal_count++;
    if (philo->meal_count == philo->table->nb_meals)
        philo->full = true;
    pthread_mutex_unlock(&philo->lock);
    drop_forks(philo);
    return (checker(philo));
}
