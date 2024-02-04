/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:25 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/04 11:56:24 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void dinner_monitor(t_table *table)
{
    int     i;
    int     monitoring;
    
    monitoring = 1;
    while(monitoring)
    {
        i = -1;
        table->nb_full_philos = 0;
        while(++i < table->nb_philo)
        {
            if(checker_philo_life(&table->philos[i]) == 1)
                monitoring = 0;
        }
        usleep(10);
    }
}

bool finish_simulation(t_philo *philo, bool flag)
{
    pthread_mutex_lock(&philo->table->finish_dinner);
    if (flag == true || philo->table->end_simulation == true)
    {
        if(flag == true)
            philo->table->end_simulation = true;
        pthread_mutex_unlock(&philo->table->finish_dinner);
        return true;
    }
    pthread_mutex_unlock(&philo->table->finish_dinner);
    return false;
}

int checker_philo_life(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->meal_time_and_quantity_checker);
    if (get_time() - philo->last_meal >= philo->table->death_time && !finish_simulation(philo, false))
    {
        pthread_mutex_lock(&philo->table->print);
        printf("%ld %d died\n", get_time() - philo->table->start_time, philo->id);
        pthread_mutex_unlock(&philo->table->print);
        finish_simulation(philo, true);
        pthread_mutex_unlock(&philo->table->meal_time_and_quantity_checker);
        return (1);
    }
    else if (philo->table->nb_meals > 0 && philo->meal_count >= philo->table->nb_meals)
    {
        philo->table->nb_full_philos++;
        if (philo->table->nb_full_philos >= philo->table->nb_philo)
        {
            finish_simulation(philo, true);
            pthread_mutex_unlock(&philo->table->meal_time_and_quantity_checker);
            return (1);
        }
    }
    pthread_mutex_unlock(&philo->table->meal_time_and_quantity_checker);
    return (0);
}


void *routine(void *philo_ptr)
{
    t_philo *philo;
    
    philo = (t_philo *) philo_ptr;
	pthread_mutex_lock(&philo->table->waiting_start_simulation);
	pthread_mutex_unlock(&philo->table->waiting_start_simulation);
    if (philo->id % 2 == 0)
		usleep(philo->table->eat_time * 1000);
    while (1) 
    {
        if (philo->table->nb_philo == 1)
        {
            dinner_for_one(philo->table);
            return (0);
        }
        if (finish_simulation(philo, false))
            return (0);
        dinner_is_served(philo);
        print_message("is sleeping", philo);
        ft_usleep(philo, philo->table->sleep_time);
        print_message("is thinking", philo);
        if (philo->table->nb_philo % 2 != 0
			&& philo->table->nb_philo <= 127)
			ft_usleep(philo, philo->table->eat_time);
    }
}

int thread_init(t_table *table)
{
    int i ;

    i = -1;
    pthread_mutex_lock(&table->waiting_start_simulation);
    table->start_time = get_time();
    while (++i < table->nb_philo) 
    {
        if(pthread_create(&table->philos[i].thread, NULL, &routine, (void *) &table->philos[i]))
			return (error("Error: Creating Threads.", table));
    }
    pthread_mutex_unlock(&table->waiting_start_simulation);
    dinner_monitor(table);
    i = -1;
    while (++i < table->nb_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (error("Error: Joining Threads.", table));
	}
	return (1);
}
