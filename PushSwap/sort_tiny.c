/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:48:03 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/01 23:00:09 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack  *find_highest_node(t_stack *stack)
{
    int         highest;
    t_stack     *highest_node;

    if (stack == NULL)
        return (NULL);
    highest = INT_MIN;
    while (stack)
    {
        if (stack->value > highest)
        {
            highest = stack->value;
            highest_node = stack;
        }
        stack = stack->next;
    }
    return (highest_node);
}
void    tiny_sort(t_stack **a)
{
    t_stack *highest_node;

    if (is_sorted(*a))
        return ;
    highest_node = find_highest_node(*a);
    if (highest_node->index == 0)
        sa(a);
    else if (highest_node->index == 1)
        rra(a);
    else if (highest_node->index == 2)
        ra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}
