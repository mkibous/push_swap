/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:17 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/22 09:42:38 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_mv_to_top(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b != NULL)
	{
		if (b->index <= (len_b) / 2 && b->index >= b->target->index)
			b->mvs_totarget = b->index;
		else if (b->target->index <= (len_a) / 2
			&& b->target->index >= b->index)
			b->mvs_totarget = b->target->index;
		else if (b->index > (len_b) / 2
			&& len_b - b->index >= len_a - b->target->index)
			b->mvs_totarget = len_b - b->index;
		else if (b->target->index > (len_a) / 2
			&& len_b - b->index <= len_a - b->target->index)
			b->mvs_totarget = len_a - b->target->index;
		else if (b->index <= (len_b) / 2 && b->target->index > (len_a) / 2)
			b->mvs_totarget = b->index + (len_a - b->target->index);
		else if (b->index > (len_b) / 2 && b->target->index <= (len_a) / 2)
			b->mvs_totarget = b->target->index + (len_b - b->index);
		b = b->next;
	}
}

t_stack	*search_best_mv(t_stack *tmp)
{
	t_stack	*best;

	best = tmp;
	while (tmp)
	{
		if (best->mvs_totarget > tmp->mvs_totarget)
		{
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}

void	best_move(t_stack **a, t_stack **b, t_stack *best)
{
	if (((best->index <= ft_lstsize(*b) / 2
				&& best->index >= best->target->index)
			|| (best->target->index <= ft_lstsize(*a) / 2
				&& best->target->index >= best->index))
		&& best->index != 0 && best->target->index != 0)
		rr(a, b, 'r');
	else if (((best->index > ft_lstsize(*b) / 2
				&& ft_lstsize(*b) - best->index
				>= ft_lstsize(*a) - best->target->index)
			|| ((best->target->index > (ft_lstsize(*a)) / 2
					&& ft_lstsize(*b) - best->index
					<= ft_lstsize(*a) - best->target->index)))
		&& best->index != 0 && best->target->index != 0)
		rrr(a, b, 'r');
	else if (best->index <= (ft_lstsize(*b) / 2) && best->index != 0)
		rotate(b, 'b');
	else if (best->index > (ft_lstsize(*b) / 2) && best->index != 0)
		r_rotate(b, 'b');
	else if (best->target->index <= (ft_lstsize(*a) / 2)
		&& best->target->index != 0)
		rotate(a, 'a');
	else if (best->target->index > (ft_lstsize(*a) / 2)
		&& best->target->index != 0)
		r_rotate(a, 'a');
}

void	do_best_move(t_stack **a, t_stack **b)
{
	t_stack	*best;

	best = search_best_mv(*b);
	while (best->index != 0 || best->target->index != 0)
	{
		best_move(a, b, best);
		ft_list_indexing(*a);
		ft_list_indexing(*b);
	}
}

void	ft_turk(t_stack **a, t_stack **b, int med)
{
	t_stack	*min_a;

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
