/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:24:18 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/20 14:57:39 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int sig_handler(int signum, siginfo_t *siginfo, void *context)
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
    kill(pid, SIGUSR2);
    return (0);
}

int main(void)
{
    struct sigaction    sig;
    int                 pid;

    pid = getpid();
    sigemptyset.sa_mask = 0;
    sig.sa_sigaction = &sig_handler; 
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    ft_printf("The process ID is --> %d \n", pid);
    while (1)
        pause();
    ft_printf("\nClosing this process...Bye ^^");
    return (0);
}


https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24