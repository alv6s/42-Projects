/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:02:23 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/01 16:13:44 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **dest, t_stack **src)
{
    t_stack *node_to_push;

    if (src == NULL || *src == NULL)
        return ;
    node_to_push = *src;
    *src = (*src)->next;
    if (*src != NULL)
        (*src)->prev = NULL;
    node_to_push->prev = NULL;
    if (*dest == NULL)
    {
        *dest = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        (*dest)->prev = node_to_push;
        *dest = node_to_push;
    }
}
void pa(t_stack **a, t_stack **b)
{
    push(a, b);
    ft_putstr_fd("pa\n", 1);
}
void pb(t_stack **a, t_stack **b)
{
    push(b, a);
    ft_putstr_fd("pb\n", 1);
}