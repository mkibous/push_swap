/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:54:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/05 15:03:15 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	t_stack	*a;
	t_stack	*b;
	int		j;
	int		l;

	l = 0;
	j = 1;
	if (arc == 1)
		exit(0);
	ft_count_nums(arc, arv, &l);
	a = NULL;
	b = NULL;
	while (arc > j)
	{
		get_numbers(&a, arv, j);
		j++;
	}
	ranking(a);
	if (l == 3)
		sort_3(&a, 'a');
	else if (l == 2 && a->content > a->next->content)
		rotate(&a, 'a');
	else if (l > 3)
		ft_turk(&a, &b, ft_lstsize(a) / 2);
	exit(0);
}
