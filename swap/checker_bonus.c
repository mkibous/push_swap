/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:54:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/23 22:23:36 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_instructions(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "sa", 3) == 0)
		return (ft_swap(a, 0), 0);
	else if (ft_strncmp(str, "sb", 3) == 0)
		return (ft_swap(b, 0), 0);
	else if (ft_strncmp(str, "ss", 3) == 0)
		return (ss(a, b, 0), 0);
	else if (ft_strncmp(str, "pa", 3) == 0)
		return (ft_push(b, a, 0), 0);
	else if (ft_strncmp(str, "pb", 3) == 0)
		return (ft_push(a, b, 0), 0);
	else if (ft_strncmp(str, "ra", 3) == 0)
		return (rotate(a, 0), 0);
	else if (ft_strncmp(str, "rb", 3) == 0)
		return (rotate(b, 0), 0);
	else if (ft_strncmp(str, "rr", 3) == 0)
		return (rr(a, b, 0), 0);
	else if (ft_strncmp(str, "rra", 4) == 0)
		return (r_rotate(a, 0), 0);
	else if (ft_strncmp(str, "rrb", 4) == 0)
		return (r_rotate(b, 0), 0);
	else if (ft_strncmp(str, "rrr", 4) == 0)
		return (rrr(a, b, 0), 0);
	return (free(str), 1);
}

int	do_inst(char *str, t_stack **a, t_stack **b)
{
	int		j;
	char	**instruction;

	instruction = ft_split(str, '\n');
	j = 0;
	free(str);
	while (instruction[j])
	{
		if (ft_instructions(a, b, instruction[j]))
			return (free(instruction[j]), 1);
		free(instruction[j]);
		j++;
	}
	free(instruction);
	return (0);
}

int	get_instructions(t_stack **a, t_stack **b)
{
	char	*str;
	char	*line;

	(1 == 1) && (str = ft__strdup(""), line = get_next_line(0));
	if (line && line[0] == '\n')
	{
		free(line);
		return (free(str), 1);
	}
	while (line)
	{
		if (str[ft_strlen(str) - 1] == '\n' && line[0] == '\n')
		{
			free(line);
			return (free(str), 1);
		}
		str = ft__strjoin(str, line);
		free(line);
		line = get_next_line(0);
	}
	if (!line && str[ft_strlen(str) - 1] != '\n')
		return (free(str), 1);
	if (do_inst(str, a, b))
		return (1);
	return (0);
}

int	main(int arc, char **arv)
{
	t_stack	*a;
	t_stack	*b;
	int		j;
	int		l;

	(1 == 1) && (l = 0, j = 1);
	ft_count_nums(arc, arv, &l);
	while (arc > j)
	{
		get_numbers(&a, arv, j);
		j++;
	}
	if (get_instructions(&a, &b) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ft_chek_if_sorted(a) == 1 && ft_lstsize(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(0);
}
