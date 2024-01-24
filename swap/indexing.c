/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:12:30 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/23 16:09:59 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_indexing(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
}

void	ft_getmin_max(t_stack *lst, int *max, int *min)
{
	*max = (*lst).content;
	*min = (*lst).content;
	while (lst != NULL)
	{
		if (lst->content > *max)
			*max = lst->content;
		if (lst->content < *min)
			*min = lst->content;
		lst = lst->next;
	}
}

void	sort_3(t_stack **lst, char c)
{
	if ((*lst)->content < (*lst)->next->content
		&& (*lst)->content < (*lst)->next->next->content
		&& (*lst)->next->content > (*lst)->next->next->content)
		r_rotate(lst, c);
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->content < (*lst)->next->next->content)
		ft_swap(lst, c);
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content > (*lst)->next->next->content)
		ft_swap(lst, c);
	if ((*lst)->content < (*lst)->next->content
		&& (*lst)->next->next->content < (*lst)->content)
		r_rotate(lst, c);
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content < (*lst)->next->next->content)
		rotate(lst, c);
}

void	ft_count_nums(int arc, char **arv, int *l)
{
	int		i;
	int		j;
	char	**s;

	i = 1;
	while (i < arc)
	{
		s = ft_split(arv[i], ' ');
		if (s[0] == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		j = 0;
		while (s[j] != NULL)
		{
			free(s[j]);
			j++;
			(*l)++;
		}
		free(s);
		i++;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
