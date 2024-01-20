/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:54:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/20 15:24:36 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_getnexnum(char *str)
{
    int i = 0;
	while (str[i] == 32 && str[i])
		i++;
    if((str[i]== '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
        i++;
    while (ft_isdigit(str[i]) && str[i])
        i++;
    if(str[i] && (str[i] != 32 && !ft_isdigit(str[i])))
    {
        ft_putstr_fd("Error\nsome arguments aren’t integers", 2);
        exit(1);
    }
	return(i);
}
void ft_printf_list(t_stack *lst, char c)
{
    while (lst != NULL)
    {
        if(c == 'b')
            ft_printf("\n<%d> -> %d -> %d", lst->content, lst->target->content, lst->mvs_totarget);
        else
            ft_printf("\n<%d>", lst->content);
        lst = lst->next;
    }
}
int ft_count_nums(int arc, char **arv)
{
    int l = 0;
    int i = 1;
    int j;
    char **s;
    while (i < arc)
    {
        s = ft_split(arv[i], ' ');
        if(s[0] == NULL)
        {
            ft_putstr_fd("Error\nargument vide", 2);
            exit(1);
        }
        j = 0;
        while (s[j] != NULL)
        {
            free(s[j]);
            j++;
            l++;
        }
        free(s);
        i++;
    }
    return(l);
}
void ft_repeat_chek(t_stack *lst, int number)
{
    while (lst != NULL)
    {
        if(number == lst->content)
        {
            ft_putstr_fd("Error \n repeated number", 2);
            exit(1);
        }
       lst = lst->next;
    }
}
void leak(void)
{
    system("leaks push_swap");
}
void sort_3(t_stack **lst, char c)
{
    if ((*lst)->content < (*lst)->next->content && (*lst)->content < (*lst)->next->next->content
            && (*lst)->next->content > (*lst)->next->next->content)
        r_rotate(lst, c);
    if ((*lst)->content > (*lst)->next->content && (*lst)->content < (*lst)->next->next->content)
        ft_swap(lst, c);
    if ((*lst)->content > (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content)
        ft_swap(lst, c);
    if ((*lst)->content < (*lst)->next->content && (*lst)->next->next->content < (*lst)->content)
        r_rotate(lst, c);
    if((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content)
        rotate(lst, c);
}
int meed(t_stack *lst)
{
    int med = 0;
    int size = ft_lstsize(lst);
	while (lst->next)
	{
        med += lst->content / size;
		lst = lst->next;
	}
    return(med);
}
int main (int arc , char **arv)
{
    // atexit(leak);
    int i = 0;
    int j = 1;
    int l = 0;
    int number = 0;
    int med = 0;
    t_stack *a;
    t_stack *b;
    a = NULL;
    b = NULL;
    while (arc > j)
    {
        i = 0;
        while (arv[j][i])
        {
            while (arv[j][i] == 32)
                i++;
            if(!arv[j][i])
                break;
            number =  (int)ft_atoi(arv[j] + i);
            ft_repeat_chek(a, number);
            ft_lstadd_back(&a, ft_lstnew(number, 0));
            l = ft_getnexnum(arv[j] + i);
            i += l; 
        }
        j++;
    }
    i = 0;
    med = ft_lstsize(a) / 2;
    
    ranking(a);
    if(ft_count_nums(arc, arv) == 3)
        sort_3(&a, 'a');
    else if (ft_count_nums(arc, arv) == 2 && a->content > a->next->content)
        rotate(&a, 'a');
    else if(ft_count_nums(arc, arv) > 3)
        ft_turk(&a, &b, med);
    exit(0);
}