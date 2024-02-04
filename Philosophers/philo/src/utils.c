/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:38 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/04 18:50:22 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n-- > 0)
		*p++ = '\0';
}

long	get_time(void)
{
	static struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(t_philo *philo, long time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < time && !finish_simulation(philo, false))
		usleep(100);
	return (0);
}

int	print_message(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->table->print);
	if (!finish_simulation(philo, false))
	{
		time = get_time() - philo->table->start_time;
		printf("%d %d %s\n", time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->table->print);
	return (1);
}
