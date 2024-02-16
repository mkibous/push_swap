/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:58 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/13 19:02:20 by mkibous          ###   ########.fr       */
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
		if (!s || s[0] == NULL)
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

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_check(char *line, int *bl)
{
	char		*tmp;

	tmp = ft_strtrim(line, "\n");
	if ((!ft_strncmp(tmp, "sa", 3) || !ft_strncmp(tmp, "sb", 3)
			|| !ft_strncmp(tmp, "ss", 3) || !ft_strncmp(tmp, "pa", 3)
			|| !ft_strncmp(tmp, "pb", 3) || !ft_strncmp(tmp, "ra", 3)
			|| !ft_strncmp(tmp, "rb", 3) || !ft_strncmp(tmp, "rr", 3)
			|| !ft_strncmp(tmp, "rra", 4) || !ft_strncmp(tmp, "rrb", 4)
			|| !ft_strncmp(tmp, "rrr", 4)))
	{
		free(tmp);
		return ;
	}
	else if (tmp[0] != '\0')
		*bl = 1;
	if (line[ft_strlen(line) - 1] == '\n' && *bl == 1)
	{
		free(tmp);
		free(line);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	free(tmp);
}
