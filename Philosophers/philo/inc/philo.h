/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:41:18 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/02 18:16:55 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
    pthread_t           thread;
    int			        id;
    bool                        full;
    bool                        eating;
    int                         last_meal;
    int                         meal_count;
    int                         time_left;
    pthread_mutex_t   first_fork;
    pthread_mutex_t   second_fork;
    pthread_mutex_t   lock;
    struct s_table   *table;
}                 t_philo;

typedef struct s_table
{
    pthread_t               *threads;
    t_philo                  *philos;
    int				nb_philo;
    int             nb_meals;
    bool            dead;
    bool            end_simulation;
    int				death_time;
    int				eat_time;
    int				sleep_time;
    int				start_time;
    int                done_meals;
    
    pthread_mutex_t	*forks;
    pthread_mutex_t lock;
    pthread_mutex_t	print;
}              t_table;

void drop_forks(t_philo *philo);
void take_forks(t_philo *philo);
int eat(t_philo *philo);
bool    check_input(int ac, char **av);

suseconds_t	get_time(void);
int	ft_usleep(int time);
int	print_message(char *str, t_philo *philo);
int ft_atoi(const char *str);
void	free_table(t_table *table);
int	error_msg(char *msg);

int   ft_philo_init(t_table *table);
int    ft_table_init(int ac, char **av, t_table *table);


int ft_monitor(t_table *table);

int checker(t_philo *philo);
void *routine(void *philo_ptr);
int thread_init(t_table *table);

void	clear_table(t_table	*table);
void	ft_exit(t_table *table);
int	error(char *str, t_table *table);
void	ft_bzero(void *s, size_t n);

#endif