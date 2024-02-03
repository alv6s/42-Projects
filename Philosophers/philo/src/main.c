/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:22 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/03 17:05:42 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_mutexes_init(t_table *table)
{
	int	i;

    pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->lock, NULL); 

	i = -1;
	while (++i < table->nb_philo)
		pthread_mutex_init(&table->forks[i], NULL);
    return (1);

}
int    ft_philo_init(t_table *table)
{
    int     i;

    i = 0;
    while( i < table->nb_philo)
    {
        table->philos[i].id = i + 1;
        table->philos[i].full = false;
        table->philos[i].eating = false;
        table->philos[i].meal_count = 0;
        table->philos[i].table = table;
        table->philos[i].last_meal = 0;
        table->philos[i].time_left = table->death_time + get_time();
        table->philos[i].first_fork = (i + 1) % table->nb_philo;
        table->philos[i].second_fork = i;
        if (table->philos[i].id % 2 == 0)
        {
            table->philos[i].first_fork = i;
            table->philos[i].second_fork = (i + 1) % table->nb_philo;
        }
        pthread_mutex_init(&table->philos[i].personal_lock, NULL);
        i++;
    }
    return (1);
}

int   ft_table_init(int ac, char **av, t_table *table)
{
    table->nb_philo = ft_atoi(av[1]);
    table->death_time = ft_atoi(av[2]);
    table->eat_time = ft_atoi(av[3]);
    table->sleep_time = ft_atoi(av[4]);
    
    if (ac == 6)
        table->nb_meals = ft_atoi(av[5]);
    else
        table->nb_meals = -1;
    table->end_simulation = false;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		error("Error: Forks Malloc incomplete.", table); //ARRANJAR !!!
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philos)
		error("Error: Philos Malloc incomplete.", table); // ARRANJAR!!!
    return (1);
    
}

int main(int ac, char **av)
{
    t_table   table;
    
    if(check_input(ac, av))
    {
        ft_bzero(&table, sizeof(t_table));
        if(ft_table_init(ac, av, &table))
        {
            if(ft_philo_init(&table))
            {
                if(ft_mutexes_init(&table))
                {
                    if(thread_init(&table))
                        ft_exit(&table);
                }
            }     
        }
        
    }
	return (0);
        
}
