/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:17 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/20 20:56:25 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_chek_if_sorted(t_stack *lst)
{
	while (lst->next)
	{
		if(lst->content > lst->next->content)
            return(0);
		lst = lst->next;
	}
    return(1);
}
void push_to_b(t_stack **a, t_stack **b, int med)
{
    int min = 0;
    int max = 0;
    ft_getmin_max(*a, &max, &min);
    while (ft_lstsize(*a) > 3 && ft_chek_if_sorted(*a) == 0)
    {
        if((*a)->rank >= med)
        {
            ft_push(a, b, 'b');
            rotate(b, 'b');
        }
        else
            ft_push(a, b, 'b');
    }
    if(ft_lstsize(*a) == 3)
        sort_3(a, 'a');
} 
t_stack *ft_getmin(t_stack *a)
{
    int max = 0;
    int min = 0;
    ft_getmin_max(a, &max, &min);
    while (a != NULL)
    {
        if (a->content == min)
        {
            break;
        }
        
        a = a->next;
    }
    return(a);
}

t_stack *ft_getmax(t_stack *a)
{
    int max = 0;
    int min = 0;
    ft_getmin_max(a, &max, &min);
    while (a != NULL)
    {
        if (a->content == max)
        {
            break;
        }
        
        a = a->next;
    }
    return(a);
}
void get_target(t_stack *a, t_stack *b)
{
    t_stack *temp_a;
    while (b != NULL)
    {
        temp_a = a;
        b->target = ft_getmax(a);
        while (temp_a != NULL)
        {
            if(temp_a->content > b->content && temp_a->content < b->target->content)
            {
                b->target = temp_a;
            }
            temp_a = temp_a->next;
        }
        if(b->target->content < b->content)
            b->target = ft_getmin(a);
        b = b->next;
    }
}
void count_mv_to_top(t_stack *a, t_stack *b)
{
    int len_a = ft_lstsize(a);
    int len_b = ft_lstsize(b);
    int imed_a = (len_a - 1) / 2;
    int imed_b = (len_b - 1) / 2;
    ft_list_indexing(b);
    ft_list_indexing(a);
    while (b != NULL)
    {
        if(b->index <= imed_b && b->index >= b->target->index)
            b->mvs_totarget = b->index;
        else if(b->target->index <= imed_a && b->target->index >= b->index)
            b->mvs_totarget = b->target->index;
        else if(b->index > imed_b && len_b - b->index >= len_a - b->target->index)
            b->mvs_totarget = len_b - b->index;
        else if(b->target->index > imed_a && b->target->index <= b->index)
            b->mvs_totarget = b->target->index;
        else if(b->index <= imed_b && b->target->index > imed_a)
            b->mvs_totarget = b->index + (len_a - b->target->index);
        else if(b->index > imed_b && b->target->index <= imed_a)
            b->mvs_totarget = b->target->index + (len_b - b->index);
        b = b->next;
    }
    
}
void do_best_move(t_stack **a, t_stack **b)
{
    ft_list_indexing(*b);
    ft_list_indexing(*a);
    int len_a = ft_lstsize(*a);
    int len_b = ft_lstsize(*b);
    int imed_a = (len_a - 1) / 2;
    int imed_b = (len_b - 1) / 2;
    t_stack *tmp;
    tmp = *b;
    t_stack *best = *b;
    while (tmp)
    {
        if(best->mvs_totarget > tmp->mvs_totarget)
        {
            best = tmp;
        }
        tmp = tmp->next;
    }
    while (best->index != 0 || best->target->index != 0)
    {
        if(best->index <= imed_b && best->target->index <= imed_a && best->target->index != 0 && best->index != 0)
            rr(a, b);
        else if(best->index > imed_b && best->target->index > imed_a && best->target->index != 0 && best->index != 0)
            rrr(a, b);
        else if(best->index <= imed_b && best->index != 0)
            rotate(b, 'b');
        else if(best->target->index <= imed_a && best->target->index != 0)
            rotate(a, 'a');
        else if(best->index > imed_b && best->index != 0)
            r_rotate(b, 'b');
        else if(best->target->index > imed_a && best->target->index != 0)
            r_rotate(a, 'a');
        ft_list_indexing(*a);
        ft_list_indexing(*b);
    }
    
}
// #include <libc.h>
// void set_cost(t_stack **stack_b, int stack_a_size, int med)
// {
//     ft_list_indexing(*stack_b);
//     t_stack    *temp_b;
//     t_stack    *cheapest_node;
//     int        cheapest;
//     int stack_b_size = ft_lstsize(*stack_b);

//     temp_b = *stack_b;
//     cheapest = INT_MAX;
//     while (temp_b)
//     {
//         if (temp_b->rank <= med)
//             temp_b->mvs_totarget = temp_b->index;
//         else
//             temp_b->mvs_totarget = stack_b_size - temp_b->index;
//         if (temp_b->target->rank <= med)
//             temp_b->target->mvs_totarget = temp_b->target->index;
//         else
//             temp_b->target->mvs_totarget = stack_a_size - temp_b->target->index;
//         if (cheapest > temp_b->mvs_totarget + temp_b->target->mvs_totarget)
//         {
//             cheapest = temp_b->mvs_totarget + temp_b->target->mvs_totarget;
//             cheapest_node = temp_b;
//         }
//         temp_b = temp_b->next;
//     }
// }
void ft_turk(t_stack **a, t_stack **b, int med)
{
    t_stack *min_a;
    push_to_b(a, b, med);
    while (ft_lstsize(*b) > 0)
    {
        ft_list_indexing(*a);
        ft_list_indexing(*b);
        get_target(*a, *b);
        count_mv_to_top(*a, *b);
        do_best_move(a, b);
        ft_push(b, a, 'a');
    }
    ft_list_indexing(*a);
    min_a = ft_getmin(*a);
    while (*a != min_a) 
    {
        if (min_a->index <= med)
            rotate(a, 'a');
        else
            r_rotate(a, 'a');
    }
    
}