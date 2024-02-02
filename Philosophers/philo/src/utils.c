/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:38 by pevieira          #+#    #+#             */
/*   Updated: 2024/02/02 21:31:48 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool    check_input(int ac, char **av) //TURBINAR!!!
{
    if (ac < 5 || ac > 6)
    {
        error("Error: Wrong format.\nUsage:  \
        ./philo nb_philos dead_time eat_time sleep_time [nb_meals]", NULL);
        return false;
    }
    else if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 1 || ft_atoi(av[3]) < 1 || \
            ft_atoi(av[4]) < 1 || (ac == 6 && ft_atoi(av[5]) < 0 ))
        {
            error("Error: Use positive numbers.", NULL);
                return false;
		}
	else if (ft_atoi(av[2]) < 60 || ft_atoi(av[3])< 60 || ft_atoi(av[4]) < 60)  ///ARRANJAR VALORES
    {
		error("Use valid inputs.", NULL);
		return false;
	}
    return true;
}
void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n-- > 0)
		*p++ = '\0';
}

int ft_atoi(const char *str)
{
	int	is_atoi;
	int	is_negative;
	int	i;

	is_atoi = 0;
	is_negative = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				is_negative = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			is_atoi = (is_atoi * 10) + str[i] - 48;
			i++;
		}
		return (is_atoi * is_negative);
	}
	return (0);
}

int	get_time(void)
{
	static struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(int time)
{
	int	start;
	
	start = get_time();
	while ((get_time() - start) < time)
		usleep(50);
	return(0);
}

int	print_message(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->table->print);
	if (philo->table->dead == false)
	{time = get_time() - philo->table->start_time;
	printf("%d %d %s\n", time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->table->print);
	return (1);
}
