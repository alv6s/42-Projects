/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:15:18 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/20 20:17:11 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(int pid, char c)
{
	int		i;

    i = 0;
	while (i < 8)
	{
		if ((c & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		c = c >> 1;
		i++;
	}

}
void send_null_character(int pid)
{
    int i;
    i = 0;
    while (i < 8)
    {
        kill(pid, SIGUSR2);
        usleep(100);
        i++;
    }
}
void    ft_error_arguments(void)
{
    ft_printf("Please use this format: ./client (SERVER'S PID) \"(YOUR MESSAGE)\"");
    exit(1);
}
int main(int ac, char **av)
{
    int i;
    int pid;

    i = 0;
    if (ac != 3)
        ft_error_arguments();
    pid = ft_atoi(av[1]);
    while (av[2][i])
    {
        char_to_bin(pid, av[2][i]);
        i++;
    }
    char_to_bin(pid, '\n');
    send_null_character(pid);
    return (0);
    
}