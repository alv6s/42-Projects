/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:20:43 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/11 23:27:47 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	get_main_index(t_stack *sa, int size)
{
	t_stack	*a;
	t_stack	*max_address;
	int		max_n;

	while (size--)
	{
		a = sa;
		max_n = INT_MIN;
		max_address = NULL;
		while (a)
		{
			if (a->n == INT_MIN && a->main_index == 0)
				a->main_index = 1;
			else if (a->n > max_n && a->main_index == 0)
			{
				max_n = a->n;
				max_address = a;
				a = sa;
			}
			else
				a = a->next;
		}
		if (max_address)
			max_address->main_index = size + 1;
	}
}*/
static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

static t_stack *new_node(int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}
static void add_node(t_stack **stack, t_stack *new)
{
    t_stack *tmp;

    if (!new)
        return ;
    if (!*stack)
        *stack = new;
    else
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

t_stack *create_stack(int ac, char **av)
{
    t_stack *a;
    long int value;
    int i;

    a = NULL;
    value = 0;
    i = 1;
    while (i < ac)
    {
        value = ft_atol(av[i]);
        if (value > INT_MAX || value < INT_MIN)
            print_error_exit(&a, NULL);
        if (i == 1)
            a = new_node((int)value);
        else
            add_node(&a, new_node((int)value));
        i++;
    }
    return (a);
}