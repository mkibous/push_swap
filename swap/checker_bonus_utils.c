/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:58 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/23 21:57:30 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
