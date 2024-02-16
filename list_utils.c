/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:40:33 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/22 09:37:44 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content, int index)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->index = index;
	lst->b = 0;
	lst->rank = 0;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*l;

	if (!lst || !new)
		return ;
	l = ft_lstlast(*lst);
	if (*lst)
		l->next = new;
	else
		*lst = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (lst && new)
		new->next = *lst;
	if (new)
		*lst = new;
}

void	rr(t_stack **a, t_stack **b, char c)
{
	rotate(a, 0);
	rotate(b, c);
}

void	rrr(t_stack **a, t_stack **b, char c)
{
	r_rotate(a, 0);
	r_rotate(b, c);
}
