/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:43:44 by pevieira          #+#    #+#             */
/*   Updated: 2023/05/05 20:23:56 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void freecontent(void *content)
{
	content = NULL;
	(void) content;
}
int	main()
{
	t_list	*new;
	t_list	*next;
	t_list *head;
	int	i;

	i=0;
	new = NULL;
	while (i < 5)
	{
		next = ft_lstnew("a"+ i);
		ft_lstadd_back(&new, next);
		i++;
	}
	head = new;
	while (new != NULL)
	{
		printf("%s\n", (char *)new->content);
		new = new->next;
	}
	
	ft_lstclear(&head, &freecontent);
	//printf("%p\n", (void *)new->content);
	
	//lstadd_back
	/*t_list	*newnew;
	t_list *last;

	newnew = ft_lstnew("Ola");
	last = ft_lstnew("Adeus");
	ft_lstadd_back(&newnew, last);
	while (newnew != NULL)
	{	
		printf("%s\n",(char *)newnew->content);
		newnew = newnew->next;
	} */
}