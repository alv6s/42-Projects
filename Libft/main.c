/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:43:44 by pevieira          #+#    #+#             */
/*   Updated: 2023/05/08 20:43:26 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 void freecontent(void *content)
{	
	free(content);
}

void	*ft_upper_str(void *content)
{
	char *newcontent;
	int	i;
	
	i=0;
	newcontent = ft_strdup((char *)content);
	while (newcontent[i])
	{
		newcontent[i] = ft_toupper(newcontent[i]);
		i++;
	}
	return ((void *)newcontent);
}
int	main()
{    //lstmap
	t_list	*new;
	t_list  *head;
	t_list *newlst = NULL;
	int	i;

	i = 0;
	head = NULL;
	while (i < 4)
	{
		new = ft_lstnew(ft_strdup("ai"));
		ft_lstadd_back(&head, new);
		i++;
	}
	newlst = ft_lstmap(head, &ft_upper_str, &freecontent);
	
	while (newlst != NULL)
	{
		printf("%s\n", (char *) newlst->content);
		newlst = newlst->next;
	}
	return (0);
}/*
{    //lstlast 
	t_list	*node;
	t_list *headernode;
	int i;
	
	headernode = NULL;
	i=0;
	while (i < 5)
	{
		node = ft_lstnew(ft_strdup("ABC"));
		ft_lstadd_back(&headernode, node);
		i++;
	}
	ft_lstadd_back(&headernode, ft_lstnew(ft_strdup("ultimo\n")));
	node = ft_lstlast(headernode);
	printf("OLa: %s", (char *) node->content);
}

{  //lsttiter 
	t_list *head;
	t_list	*current;
	int	i;
	
	i = 0;
	head = NULL;
	while (i++ < 5)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup("Ola")));
	}
	current = head;
	i = 0;
	while(i++ < 5)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
	ft_lstiter(head, &changevalue);
	printf("Depois da alteracao: \n");
	i = 0;
	current = head;
	while(i++ < 5)
	{	
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
}

	//lstclean 
{ 
	t_list	*new;
	t_list	*next;
	t_list *head;
	int	i;

	i=0;
	new = NULL;
	while (i < 5)
	{
		next = ft_lstnew("a");
		ft_lstadd_back(&new, next);
		i++;
	}
	head = new;
	while (new != NULL)
	{
		printf(-C= newnew->next;
	} 
}
*/