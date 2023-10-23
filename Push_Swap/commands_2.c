/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:52:39 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/22 17:07:08 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack			*last;
	int				len;

	len = stack_len(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	last = get_lst_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		len;

	len = stack_len(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	last = get_lst_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	command_rotation(t_stack **a, t_stack **b, char *choice)
{
	if (ft_strcmp(choice, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(choice, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(choice, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(choice, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(choice, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(choice, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	ft_putstr_fd(choice, 1);
	ft_putstr_fd("\n", 1);
}
