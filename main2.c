#include "libft.h"
int	main()
{
	t_list	*head;
	t_list	*new;
	int	i;

	i=0;
	head = NULL;
	while (i < 5)
	{
		new = ft_lstnew(ft_strdup("ola"));
		ft_lstadd_back(&head,new);
		i++;
	}
	while(head != NULL)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}