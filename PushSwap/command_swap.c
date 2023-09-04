/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:18:39 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/01 16:34:16 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **head)
{
    int tmp;
    
    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return ;
    tmp = (*head)->value;
    (*head)->value = (*head)->next->value;
    (*head)->next->value = tmp;
    tmp = (*head)->index;
    (*head)->index = (*head)->next->index;
    (*head)->next->index = tmp;
}
void sa(t_stack **a)
{
    swap(a);
    ft_putstr_fd("sa\n", 1);
}
void sb(t_stack **b)
{
    swap(b);
    ft_putstr_fd("sb\n", 1);
}
void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_putstr_fd("ss\n", 1);
}
