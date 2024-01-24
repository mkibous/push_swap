/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:17 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/22 10:00:41 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranking(t_stack *lst)
{
	int		rank;
	t_stack	*tmp;
	t_stack	*first;

	rank = 0;
	first = lst;
	while (rank < ft_lstsize(lst))
	{
		tmp = ft_getmax(lst);
		while (lst)
		{
			if (tmp->content > lst->content && lst->b == 0)
				tmp = lst;
			lst = lst->next;
		}
		if (tmp->b == 0)
		{
			tmp->rank = rank;
			tmp->b = 1;
		}
		rank++;
		lst = first;
	}
}

void	push_to_b(t_stack **a, t_stack **b, int med)
{
	while (ft_lstsize(*a) > 3 && ft_chek_if_sorted(*a) == 0)
	{
		if ((*a)->rank > med)
		{
			ft_push(a, b, 'b');
			rotate(b, 'b');
		}
		else
			ft_push(a, b, 'b');
	}
	if (ft_lstsize(*a) == 3)
		sort_3(a, 'a');
}

t_stack	*ft_getmin(t_stack *a)
{
	int	max;
	int	min;

	max = 0;
	min = 0;
	ft_getmin_max(a, &max, &min);
	while (a != NULL)
	{
		if (a->content == min)
		{
			break ;
		}
		a = a->next;
	}
	return (a);
}

t_stack	*ft_getmax(t_stack *a)
{
	int	max;
	int	min;

	max = 0;
	min = 0;
	ft_getmin_max(a, &max, &min);
	while (a != NULL)
	{
		if (a->content == max)
		{
			break ;
		}
		a = a->next;
	}
	return (a);
}

void	get_target(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;

	while (b != NULL)
	{
		temp_a = a;
		b->target = ft_getmax(a);
		while (temp_a != NULL)
		{
			if (temp_a->content > b->content
				&& temp_a->content < b->target->content)
			{
				b->target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (b->target->content < b->content)
			b->target = ft_getmin(a);
		b = b->next;
	}
}
