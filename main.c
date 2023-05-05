/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:43:44 by pevieira          #+#    #+#             */
/*   Updated: 2023/05/05 19:37:58 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{

	//lstadd_back
	t_list	*newnew;
	t_list *last;

	newnew = ft_lstnew("Ola");
	last = ft_lstnew("Adeus");
	ft_lstadd_back(&newnew, last);
	while (newnew != NULL)
	{	
		printf("%s\n",(char *)newnew->content);
		newnew = newnew->next;
	}
}