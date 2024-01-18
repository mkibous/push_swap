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
int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
void  ft_swap(t_stack **lst, char c)
{
    t_stack *tmp;
	if((*lst)->next == NULL)
		return ;
    tmp = (*lst)->next;
    (*lst)->next = (*lst)->next->next;
    ft_lstadd_front(lst, tmp);
	if(c != 0 && (*lst)->next != NULL)
		ft_printf("s%c\n", c);
}
void ft_push(t_stack **src, t_stack **dest, char c)
{
    t_stack *tmp;
	if((*src) == NULL)
		return ;
    tmp = (*src)->next; 
    ft_lstadd_front(dest, *src);
    *src = tmp;
	if(c != 0)
		ft_printf("p%c\n", c);
}
void rotate(t_stack **lst, char c)
{

    t_stack *tmp;
    tmp = (*lst);
    *lst = NULL;
    *lst = tmp->next;
    tmp->next = NULL;
    ft_lstadd_back(lst, tmp);
	if(c != 0 && (*lst)->next != NULL)
		ft_printf("r%c\n", c);
}
void r_rotate(t_stack **lst, char c)
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
	if(c != 0 && (*lst)->next != NULL)
		ft_printf("rr%c\n", c);
}
void ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 0);
	ft_swap(b, 's');
}
void rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 'r');
}
void rrr(t_stack **a, t_stack **b)
{
	r_rotate(a, 0);
	r_rotate(b, 'r');
}