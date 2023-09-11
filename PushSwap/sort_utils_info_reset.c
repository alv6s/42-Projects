/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_info_reset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:18:14 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/11 23:27:01 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (stack == NULL)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*a_current;
	t_stack *target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		a_current = a;
		while (a_current)
		{
			if (a_current->value > b->value)
			{
				target_node = a_current;
				best_match_index = a_current->value;
			}
			a_current = a_current->next;
		}
		if (LONG_MAX == best_match_index)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);

	while (b)
	{
		b->push_price = b->index;
		if (!(b->above_median))
			b->push_price = len_b - (b->index);
		if (b->target->above_median)
			b->push_price += b->target->index;
		else
			b->push_price += len_a -(b->target->index);
		b = b->next;
	}
}

void	set_cheapest_node(t_stack *b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest_push = 1;
}

void	reset_node_info(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a,b);
	set_price(a,b);
	set_cheapest_node(b);
}