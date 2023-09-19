/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:30 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/19 15:58:18 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_lst_node(t_stack *stack_head)
{
	if (NULL == stack_head)
		return (NULL);
	while (stack_head->next)
		stack_head = stack_head->next;
	return (stack_head);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = get_lst_node(*stack);
		last->next = node;
		node->prev = last;
	}
}

t_stack	*get_minimum(t_stack *stack)
{
	long			smallest;
	t_stack			*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
