/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:20:43 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/01 23:59:17 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *new_node(int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}
static void add_node(t_stack **stack, t_stack *new)
{
    t_stack *tmp;

    if (!new)
        return ;
    if (!*stack)
        *stack = new;
    else
    {
        tmp = stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

t_stack *create_stack(int ac, char **av)
{
    t_stack *a;
    long int value;
    int i;

    a = NULL;
    value = 0;
    i = 1;
    while (i < ac)
    {
        value = ft_atoi(av[i]);
        if (value > INT_MAX || value < INT_MIN)
            print_error_exit(&a, NULL);
        if (i == 1)
            a = new_node((int)value);
        else
            add_node(&a, new_node((int)value));
        i++;
    }
    return (a);
}