/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:11:42 by pevieira          #+#    #+#             */
/*   Updated: 2023/09/05 12:06:04 by pevieira         ###   ########.fr       */
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

#endif