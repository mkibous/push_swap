/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:16:05 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/19 15:43:44 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*s;

	if (!lst || !del)
		return ;
	while (lst && *lst)
	{
		s = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = s;
	}
}
