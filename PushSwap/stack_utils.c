/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:34:47 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/01 15:56:40 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr_fd(char *s, int fd)
{
    while (*s)
        write(fd, s++, 1);
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *current;

    if (!stack || !*stack)
        return ;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        free (current);
        current = tmp;
    }
    *stack = NULL;
}
void    print_error_exit(t_stack **a, t_stack **b)
{
    if (!a || *a)
        free_stack(a);
    if (!b || *b)
        free_stack(b);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}