/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:25 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/02 22:45:11 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*static int death_check(t_philo *philo)
{
    if (philo->full == false && (get_time() - philo->table->start_time > philo->time_left) && philo->eating == false) 
    {
        printf("%d %d died\n", get_time() - philo->table->start_time, philo->id);
        philo->table->dead = true;
        philo->table->end_simulation = true;
        usleep(100);
        return (0);
    }
    return (1);
}*/

int monitor(t_table *table)
{
    int     i;
    int         full_philo;
    
    i = 0;
    full_philo = 0;
    while(i < table->nb_philo)
    {
        pthread_mutex_lock(&table->philos[i].lock);
        if(table->philos[i].full == true)
        {
            full_philo++;
        }
        pthread_mutex_unlock(&table->philos[i].lock);
        if (checker(&table->philos[i])) //MUDEI AQUI  para o checker
            return (0);
        usleep(200);
        if (table->done_meals == table->nb_philo)
        {   
            pthread_mutex_lock(&table->lock);
            printf("%d", full_philo);
            table->end_simulation = true;
            return (0);
            pthread_mutex_unlock(&table->lock);
        }
        i++;
    }
    return (full_philo != table->nb_philo );
}
/*
int checker(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock);
    if(philo->table->nb_meals != -1 && philo->meal_count == philo->table->nb_meals)
    {
		philo->full = true;
	    pthread_mutex_unlock(&philo->lock);
		return (1);
    }
    pthread_mutex_unlock(&philo->lock);
    if (philo->table->dead == true)
        return (1);
    if (philo->full == false && (get_time() - philo->table->start_time > philo->time_left) && philo->eating == false) 
    {
        pthread_mutex_lock(&philo->table->lock);
        printf("%d %d died\n", get_time() - philo->table->start_time, philo->id);
        philo->table->dead = true;
        philo->table->end_simulation = true;
        usleep(100);
        pthread_mutex_unlock(&philo->table->lock);
        return (1);
    }
    return (0);
}*/
int checker(t_philo *philo) 
{
    int result = 0;
    pthread_mutex_lock(&philo->lock);
    if (philo->table->nb_meals != -1 && philo->meal_count >= philo->table->nb_meals) 
    {
        result = 1;
    }
    pthread_mutex_unlock(&philo->lock);
    
    pthread_mutex_lock(&philo->table->lock);
    if (philo->table->dead) 
    {
        result = 1;
    }
    pthread_mutex_lock(&philo->lock);
    if (philo->full == false && (get_time() > philo->time_left) && philo->eating == false) 
    {
        pthread_mutex_lock(&philo->table->print);
        printf("%d %d died\n", get_time() - philo->table->start_time, philo->id);
        philo->table->dead = true;
        philo->table->end_simulation = true;
        pthread_mutex_unlock(&philo->table->print);
        result = 1;
    }
    pthread_mutex_unlock(&philo->lock);
    pthread_mutex_unlock(&philo->table->lock);
    
    return result;
}

void *routine(void *philo_ptr)
{
    t_philo *philo;
    
    philo = (t_philo *) philo_ptr;
    while (philo->table->end_simulation == false)
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
    while (++i < table->nb_philo) 
    {
        if(pthread_create(&table->philos[i].thread, NULL, &routine, (void *) &table->philos[i]))
			return (error("Error: Creating Threads.", table));
    }
    table->start_time = get_time();
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