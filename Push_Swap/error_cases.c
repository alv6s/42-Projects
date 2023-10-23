/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:53:21 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/22 17:09:33 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_and_print_error(t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_existing_repetitions(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_nbr_validation(char *nbr)
{
	if ((nbr[0] != '+' && nbr[0] != '-') && !(nbr[0] >= '0' && nbr[0] <= '9'))
		return (1);
	if ((nbr[0] == '+' || nbr[0] == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	if (nbr[0] == '+' || nbr[0] == '-')
		nbr++;
	while (*nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (1);
		nbr++;
	}
	return (0);
}
