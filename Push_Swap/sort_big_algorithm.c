/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:54:59 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/22 17:03:38 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		command_rotation(a, b, "rr");
	set_index(*a);
	set_index(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		command_rotation(a, b, "rrr");
	set_index(*a);
	set_index(*b);
}

void	ending_rotation(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				command_rotation(stack, NULL, "ra");
			else
				command_rotation(stack, NULL, "rra");
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				command_rotation(NULL, stack, "rb");
			else
				command_rotation(NULL, stack, "rrb");
		}
	}
}

static void	moves(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_rotate_both(a, b, cheapest);
	ending_rotation(b, cheapest, 'b');
	ending_rotation(a, cheapest->target, 'a');
	command_push(a, b, "pa");
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack			*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			command_push(a, b, "pb");
	}
	sort_three(a);
	while (*b)
	{
		set_nodes_info(*a, *b);
		moves(a, b);
	}
	set_index(*a);
	smallest = get_minimum(*a);
	if (smallest->above_median)
		while (*a != smallest)
			command_rotation(a, NULL, "ra");
	else
		while (*a != smallest)
			command_rotation(a, NULL, "rra");
}
