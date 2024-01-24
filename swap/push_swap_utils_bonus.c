/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:54:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/22 16:31:05 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getnexnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
		i++;
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (str[i] && (str[i] != 32 && !ft_isdigit(str[i])))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (i);
}

void	ft_repeat_chek(t_stack *lst, int number)
{
	while (lst != NULL)
	{
		if (number == lst->content)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		lst = lst->next;
	}
}

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

void	get_numbers(t_stack **a, char **arv, int j)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (arv[j][i])
	{
		while (arv[j][i] == 32)
			i++;
		if (!arv[j][i])
			break ;
		number = ft_atoi(arv[j] + i);
		ft_repeat_chek(*a, number);
		ft_lstadd_back(a, ft_lstnew(number, 0));
		i += ft_getnexnum(arv[j] + i);
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}
