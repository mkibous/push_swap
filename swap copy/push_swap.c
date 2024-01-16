/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:54:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/16 22:47:25 by mkibous          ###   ########.fr       */
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

void ft_printf_list(t_stack *lst)
{
    while (lst != NULL)
    {
        ft_printf("%d<%d>", lst->index, lst->content);
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
// void sort_3(t_stack *lst)
// {
//     if (lst->content > lst->next->content && lst->next->next->content < lst->content 
//         && lst->next->next->content > lst->next->content)
//         rotate(&lst);
//     if(lst->content > lst->next->content && lst->next->next->content > lst->next->content
//         && lst->next->next->content > lst->next->content)
//         ft_swap(&lst);
//     /////////////////////////////////////////
        
// }
int main (int arc , char **arv)
{
    // atexit(leak);
    int i = 0;
    int j = 1;
    int l = 0;
    int max = 0;
    int min = 0;
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
    ft_getmin_max(a, &max, &min);
    med = (max + min) / 2;
    ft_swap(&a);
    ft_printf ("A :  ");
    r_rotate(&a);
    ft_list_indexing(a);
    ft_printf_list(a);
    ft_printf("med : %d  max : %d  min = %d", med, max , min);
    exit(0);
}