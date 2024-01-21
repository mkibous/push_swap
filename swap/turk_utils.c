/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:17 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/21 22:32:48 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chek_if_sorted(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
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
