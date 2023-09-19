/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:55:27 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/19 15:55:39 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_maximum(t_stack *stack)
{
	int				highest;
	t_stack			*highest_node;

	if (!stack)
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

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack **a)
{
	t_stack	*highest;

	highest = get_maximum(*a);
	if (*a == highest)
		command_rotation(a, NULL, "ra");
	else if ((*a)->next == highest)
		command_rotation(a, NULL, "rra");
	if ((*a)->value > (*a)->next->value)
		command_swap(a, NULL, "sa");
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		set_nodes_info(*a, *b);
		ending_rotation(a, get_minimum(*a), 'a');
		command_push(a, b, "pb");
	}
}
