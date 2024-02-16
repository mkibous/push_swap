/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:40:37 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/11 21:48:22 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **lst, char c)
{
	t_stack	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		ft_lstadd_front(lst, tmp);
	}
	if (c != 0 && (*lst)->next != NULL)
		ft_printf("s%c\n", c);
}

void	ft_push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*tmp;

	if ((*src) == NULL)
		return ;
	tmp = (*src)->next;
	ft_lstadd_front(dest, *src);
	*src = tmp;
	if (c != 0)
		ft_printf("p%c\n", c);
}

void	rotate(t_stack **lst, char c)
{
	t_stack	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst);
		*lst = NULL;
		*lst = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(lst, tmp);
	}
	if (c != 0 && (*lst)->next != NULL)
		ft_printf("r%c\n", c);
}

void	r_rotate(t_stack **lst, char c)
{
	t_stack	*last;

	last = ft_lstlast(*lst);
	ft_lstadd_front(lst, last);
	if (*lst && (*lst)->next)
	{
		while ((*lst)->next != last)
		{
			(*lst) = (*lst)->next;
		}
		(*lst)->next = NULL;
		*lst = last;
	}
	if (c != 0 && (*lst)->next != NULL)
		ft_printf("rr%c\n", c);
}

void	ss(t_stack **a, t_stack **b, char c)
{
	ft_swap(a, 0);
	ft_swap(b, c);
}
