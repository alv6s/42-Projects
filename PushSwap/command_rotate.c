/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:09:50 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/01 23:19:24 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *last_node;
    int len;
    
    len = stack_len(*stack);
    if (stack == NULL || *stack == NULL || len == 1)
        return ;
    last_node = find_last_node(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void ra(t_stack **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}
void rb(t_stack **b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1);
}