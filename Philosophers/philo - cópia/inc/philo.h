/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:41:18 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/04 18:56:22 by pevieira         ###   ########.fr       */
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
	pthread_t		thread;
	int				id;
	long			last_meal;
	int				meal_count;
	int				time_left;
	int				first_fork;
	int				second_fork;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				nb_philo;
	int				nb_meals;
	int				eat_time;
	int				sleep_time;
	int				death_time;
	long			start_time;
	int				nb_full_philos;
	bool			end_simulation;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	finish_dinner;
	pthread_mutex_t	waiting_start_simulation;
	pthread_mutex_t	meal_time_and_quantity_checker;
}	t_table;

void	drop_forks(t_philo *philo);
void	take_forks(t_philo *philo);
bool	check_input(int ac, char **av);
long	get_time(void);
int		ft_usleep(t_philo *philo, long time);
int		print_message(char *str, t_philo *philo);
int		ft_atoi(const char *str);
void	free_table(t_table *table);
int		error_msg(char *msg);
void	dinner_for_one(t_table *table);
int		ft_philo_init(t_table *table);
int		ft_table_init(int ac, char **av, t_table *table);
void	dinner_is_served(t_philo *philo);
int		ft_monitor(t_table *table);
bool	finish_simulation(t_philo *philo, bool flag);
int		checker(t_philo *philo);
void	*routine(void *philo_ptr);
int		thread_init(t_table *table);
int		checker_philo_life(t_philo *philo);
void	clear_table(t_table	*table);
void	ft_exit(t_table *table);
int		error(char *str, t_table *table);
void	ft_bzero(void *s, size_t n);
void	dinner_monitor(t_table *table);
int		is_nb(int c);
int		str_is_nb(char *str);
int		arguments_are_nbs(char **av);
#endif