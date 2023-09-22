/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:24:18 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/22 14:03:48 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signum)
{
    static int  i = 0;
    static char c = 0;

    if (signum == SIGUSR1)
        c = c | (1 << i);
    i++;
    if (i == 8)
    {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
}

void sig2_handler(int sig)
{
    (void) sig;
    ft_printf("\nTime to sleep...Bye!\n");
    exit(0);
}
int main(void)
{
    struct sigaction    sa;
    struct sigaction    se;
    int                 pid;

    pid = getpid();
    sigemptyset(&sa.sa_mask);
    sigemptyset(&se.sa_mask);
    sa.sa_handler = &sig_handler;
    sa.sa_flags = SA_SIGINFO;
    se.sa_handler = &sig2_handler;
    se.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGINT, &se, NULL);
    ft_printf("Hello! The ID of this process is: %d \n", pid);
    while (1)
        pause();
    return (0);
}
