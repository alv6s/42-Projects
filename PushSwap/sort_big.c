/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:05:13 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/05 15:20:48 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a,b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a,b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	move_nodes_end(t_stack **stack, t_stack *cheapest_node, char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name = 'a')
		{
			if (cheapest_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name = 'b')
		{
			if (cheapest_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a,b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		rev_rotate_both(a,b, cheapest_node);
	move_nodes_end(b, cheapest_node, 'b');
	move_nodes_end(a, cheapest_node->target, 'a');
	pa(a, b);
}

void	sort_big(t_stack **a, t_stack **b)
{
	while (*b)
	{
		reset_node_info(*a,*b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest= find_smallest(*a);
	if (smallest-> above_median)
	{
		while (*a != smallest)
			ra(a);
	}
	else
	{
		while (*a != smallest)
			rra(a);
	}
}
