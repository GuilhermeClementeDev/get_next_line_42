#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	new->next = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
t_list	*ft_lstnew(void *string)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->string = string;
	tmp->next = NULL;
	return (tmp);
}
void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, free());
		*lst = tmp;
	}
	*lst = NULL;
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->string);
	free(lst);
	lst = NULL;
}
