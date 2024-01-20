#include "push_swap.h"
void ft_list_indexing(t_stack *lst)
{
    int i = 0;
    while (lst != NULL)
    {
        lst->index = i;
        lst = lst->next;
        i++;
    }
}

void ft_getmin_max(t_stack *lst, int *max, int *min)
{
    *max = (*lst).content;
    *min = (*lst).content;
    while (lst != NULL)
    {
        if (lst->content > *max)
            *max = lst->content;
        if(lst->content < *min)
            *min = lst->content;
        lst = lst->next;
    }
}

void ranking(t_stack *lst)
{
    int rank;
    t_stack *tmp;
    t_stack *first;

    rank = 0;
    first = lst;
    while (rank < ft_lstsize(lst))
    {
        tmp = ft_getmax(lst);
        while (lst)
        {
            if(tmp->content > lst->content && lst->b == 0)
                tmp = lst;
            lst = lst->next;
        }
        if(tmp->b == 0)
        {
            tmp->rank = rank;
            tmp->b = 1;
        }
        rank++;
        lst = first;
    }
}