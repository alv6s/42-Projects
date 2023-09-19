/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:54:28 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/19 15:54:32 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (NULL == stack)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target(t_stack *a,
							t_stack *b)
{
	t_stack			*current_a;
	t_stack			*target;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target = get_minimum(a);
		else
			b->target = target;
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
			b->push_price += len_a - (b->target->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long			best_match_value;
	t_stack			*best_match;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match = b;
		}
		b = b->next;
	}
	best_match->cheapest = true;
}

void	set_nodes_info(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
