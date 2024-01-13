/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:54:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/13 22:46:23 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_getnexnum(char *str, int n)
{
    int l;
    int i = n;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i--;
    while (ft_isdigit(str[i]))
        i--;
	while(str[i] == '+' || str[i] == '-')
		i--;
    l = n - i; 
	return(l);
}
void ft_printf_list(t_list *lst)
{
    while (lst != NULL)
    {
        ft_printf("%d", *(int *)lst->content);
        lst = lst->next;
    }
}
int main (int arc , char **arv)
{
    int i = 0;
    arc--;
    int n = 0;
    int number = 0;
    t_list *a;
    a = NULL;
    while (arc > 0)
    {
        i = 0;
        n = (int)ft_strlen(arv[arc]) - 1;
        while (0 <= n)
        {
            n -= ft_getnexnum(arv[arc], n);
            number =  ft_atoi(arv[arc] + n);
            ft_printf("|%d|", number);
            ft_lstadd_back(&a, ft_lstnew(&number));
            
        }
        arc--;
    }
    ft_printf_list(a);
}