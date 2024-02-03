/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:25 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/03 17:08:29 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static bool is_simulation_ended(t_philo *philo)
{
    int result;

    pthread_mutex_lock(&philo->table->lock);
    result = philo->table->end_simulation;
    pthread_mutex_unlock(&philo->table->lock);
    return result;
}

int monitor(t_table *table)
{
    int     i;
    int         full_philo;
    
    i = 0;
    full_philo = 0;
    while(i < table->nb_philo)
    {
        pthread_mutex_lock(&table->philos[i].personal_lock);
        if(table->philos[i].full == true)
        {
            full_philo++;
        }
        pthread_mutex_unlock(&table->philos[i].personal_lock);
        if (checker(&table->philos[i]))
            return (0);
        if (table->done_meals == table->nb_philo)
        {   
            pthread_mutex_lock(&table->lock);
            table->end_simulation = true;
            pthread_mutex_unlock(&table->lock);
            return (0);
        }
        i++;
        usleep(10); //Adiçao
    }
    return (full_philo != table->nb_philo );
}

int checker(t_philo *philo) 
{
    int result = 0;
    pthread_mutex_lock(&philo->personal_lock);
    if (philo->table->nb_meals != -1 && philo->meal_count >= philo->table->nb_meals) 
        result = 1;
    pthread_mutex_unlock(&philo->personal_lock);
    pthread_mutex_lock(&philo->table->lock);
    if (philo->table->dead) 
    {
        result = 1;
        philo->table->end_simulation = true;  // AQUI DATA RACE
    }
    pthread_mutex_unlock(&philo->table->lock);
    pthread_mutex_lock(&philo->personal_lock);
    if (philo->full == false && (get_time() > philo->time_left) && philo->eating == false) 
    {
		pthread_mutex_lock(&philo->table->lock);
        philo->table->dead = true;
        philo->table->end_simulation = true;  // AQUI DATA RACE
		pthread_mutex_unlock(&philo->table->lock);
        pthread_mutex_lock(&philo->table->print);
        printf("%d %d died\n", get_time() - philo->table->start_time, philo->id);
        pthread_mutex_unlock(&philo->table->print);
        result = 1;
    }
    pthread_mutex_unlock(&philo->personal_lock);
    return result;
}


void *routine(void *philo_ptr)
{
    t_philo *philo;
    
    philo = (t_philo *) philo_ptr;

	pthread_mutex_lock(&philo->table->lock);
	pthread_mutex_unlock(&philo->table->lock);
    if (philo->id % 2 == 0) //adicao
		usleep(philo->table->eat_time * 1000);
    while (is_simulation_ended(philo) == false) 
    {
        if(!checker(philo))
        {
            if (eat(philo) == 1)
               break;
        }
        if(!checker(philo))
            print_message("is thinking", philo);
    }
    return NULL;
}

int thread_init(t_table *table)
{
    int i ;

    i = -1;
    pthread_mutex_lock(&table->lock);
    table->end_simulation = false;
    table->start_time = get_time(); //mudamos 1
    while (++i < table->nb_philo) 
    {
        if(pthread_create(&table->philos[i].thread, NULL, &routine, (void *) &table->philos[i]))
			return (error("Error: Creating Threads.", table));
    }
    //table->start_time = get_time();  antes 1
    pthread_mutex_unlock(&table->lock);
    i = -1;
    while(monitor(table))
        ;
    while (++i < table->nb_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (error("Error: Joining Threads.", table));
	}
	return (0);
}