/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:57:27 by pevieira          #+#    #+#             */
/*   Updated: 2023/04/28 18:39:54 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	list_lenght;

	list_lenght = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		list_lenght++;
	}
	return (list_lenght);
}
