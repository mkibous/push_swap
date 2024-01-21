/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:12:30 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/21 21:14:17 by mkibous          ###   ########.fr       */
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
			ft_putstr_fd("Error\nargument vide", 2);
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
