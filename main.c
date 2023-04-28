#include <stdlib.h>
#include <stdio.h>

typedef	struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	ft_freecontent(void *content)
{
	content = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextlst;
	t_list	*current;
	
	if (lst != NULL && del != NULL)
	{
		current = *lst;
		while (current != NULL)
		{
			nextlst = current->next;
			del(current->content);
			free(current);
			current = nextlst;	
		}
		*lst = NULL;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;
	
	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return NULL;
	new->content = content;
	new->next = NULL;
	return new;
}

void printlist(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}


int main()
{
	t_list	*l1 = ft_lstnew("ola");
	t_list	*l2 = ft_lstnew("adeus");

	l1->next = l2;
	printlist(l1);
	ft_lstclear(&l1, &ft_freecontent);
	printf("%p\n",(void *)l1);
}