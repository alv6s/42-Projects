/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:11:42 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/07 15:56:43 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
    int				value;
    int				index; //position/index on the stack
    int				push_price;  // price to push to theother stack   cost = how many moves 
    int             above_median;
	int				cheapest_push; // 1 if it is the chepest to push
    struct s_stack	*target;
    struct s_stack	*next;
    struct s_stack	*prev;
}				t_stack;

void ft_putstr_fd(char *s, int fd);
void free_stack(t_stack **stack);
void    print_error_exit(t_stack **a, t_stack **b);
t_stack	*cheapest(t_stack *stack);
int	stack_len(t_stack *stack);
t_stack	*find_last_node(t_stack *head);
t_stack	*find_smallest(t_stack *stack);

t_stack *create_stack(int ac, char **av);

void	reset_node_info(t_stack *a, t_stack *b);
void	set_cheapest_node(t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	set_index(t_stack *stack);

void	sort_five(t_stack **a, t_stack **b);
void    sort_three(t_stack **a);
void	sort_big(t_stack **a, t_stack **b);
int	is_sorted(t_stack *s);

void ss(t_stack **a, t_stack **b);
void sb(t_stack **b);
void sa(t_stack **a);

void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);

#endif