#include "push_swap.h"
t_stack	*ft_lstnew(int content, int index)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
    lst->index = index;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*l;

	if (!lst || !new)
		return ;
	l = ft_lstlast(*lst);
	if (*lst)
		l->next = new;
	else
		*lst = new;
}
t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next) 
			lst = lst->next;
	}
	return (lst);
}
void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (lst && new)
		new->next = *lst;
	if (new)
		*lst = new;
}
void  ft_swap(t_stack **lst)
{
    t_stack *tmp;
    tmp = (*lst)->next;
    (*lst)->next = (*lst)->next->next;
    ft_lstadd_front(lst, tmp);
}
void ft_push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;
    tmp = (*src)->next; 
    ft_lstadd_front(dest, *src);
    *src = tmp;
}
void rotate(t_stack **lst)
{

    t_stack *tmp;
    tmp = (*lst);
    *lst = NULL;
    *lst = tmp->next;
    tmp->next = NULL;
    ft_lstadd_back(lst, tmp);
}
void r_rotate(t_stack **lst)
{
    t_stack *last;
    last = ft_lstlast(*lst);
    ft_lstadd_front(lst, last);
    if (*lst)
	{
		while ((*lst)->next != last)
        {
			(*lst) = (*lst)->next;
        }
        (*lst)->next = NULL;
	}
    *lst = last;
}