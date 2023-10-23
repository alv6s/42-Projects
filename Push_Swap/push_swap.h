/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:50:35 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/22 17:10:56 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					push_price;
	bool				cheapest;
	bool				above_median;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;	

void			ft_putstr_fd(char *s, int fd);
void			free_and_print_error(t_stack **a);
void			free_stack(t_stack **stack);
int				check_existing_repetitions(t_stack *a, int nbr);
int				check_nbr_validation(char *str_nbr);

void			stack_creator(t_stack **a, char **av);
void			set_nodes_info(t_stack *a, t_stack *b);
void			set_index(t_stack *stack);
void			set_price(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);

void			append_node(t_stack **stack, int nbr);
t_stack			*get_lst_node(t_stack *stack_head);
t_stack			*get_minimum(t_stack *stack);
t_stack			*return_cheapest(t_stack *stack);
bool			stack_sorted(t_stack *stack);
int				stack_len(t_stack *stack);
void			ending_rotation(t_stack **stack, t_stack *top, char stack_name);

void			sort_three(t_stack **a);
void			sort_five(t_stack **a, t_stack **b);
void			push_swap(t_stack **a, t_stack **b);

int				ft_strcmp(char *s1, char *s2);
void			command_swap(t_stack **a, t_stack **b, char *choice);
void			command_push(t_stack **a, t_stack **b, char *choice);
void			command_rotation(t_stack **a, t_stack **b, char *choice);

#endif
