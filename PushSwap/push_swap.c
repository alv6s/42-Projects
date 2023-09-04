/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:11:13 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/01 14:58:57 by pevieira         ###   ########.fr       */
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
    else if(size <= 5 && !is_sorted(*a))
        sort_five(a, b);
    else if(size > 5 && !is_sorted(*a))
        sort_big(a, b, size);
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