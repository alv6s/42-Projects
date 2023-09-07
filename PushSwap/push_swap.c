/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:11:13 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/07 16:03:18 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *s)
{
    t_stack *st;

    st = s;
    while (st->next)
    {
        if(st->value > st->next->value)
            return (0);
        st = st->next;
    }
    return (1);
}
static void push_swap(t_stack **a, t_stack **b, int size)
{
    if(size == 2 && !is_sorted(*a))
        sa(a);
    else if(size == 3 && !is_sorted(*a))
        sort_three(a);
    else if(size == 5 && !is_sorted(*a))
        sort_five(a, b);
    else if(!is_sorted(*a))
	{
		while(size-- > 3)
			pb(b,a);
		sort_three(a);
        sort_big(a, b);
	}
}

int main(int ac, char **av)
{
    int size;
    t_stack *a;
    t_stack *b;

    if (ac < 2)
        return (0);
    if(!is_correct_input(av))
        print_error_exit(NULL, NULL);
    a = creat_stack(a, av);
    b = NULL;
    size = stack_size(a);
    get_main_index(a, size);
    push_swap(&a, &b, size);
    free_stack(&a);
    free_stack(&b);
}