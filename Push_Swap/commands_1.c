/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:49:55 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/22 17:08:35 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

static void	swap(t_stack **head)
{
	int	len;

	len = stack_len(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	command_push(t_stack **a, t_stack **b, char *choice)
{
	if (ft_strcmp(choice, "pa") == 0)
		push(a, b);
	else if (ft_strcmp(choice, "pb") == 0)
		push(b, a);
	ft_putstr_fd(choice, 1);
	ft_putstr_fd("\n", 1);
}

void	command_swap(t_stack **a, t_stack **b, char *choice)
{
	if (ft_strcmp(choice, "sa") == 0)
		swap(a);
	else if (ft_strcmp(choice, "sb") == 0)
		swap(b);
	else if (ft_strcmp(choice, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	ft_putstr_fd(choice, 1);
	ft_putstr_fd("\n", 1);
}
