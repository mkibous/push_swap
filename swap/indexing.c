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