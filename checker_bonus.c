/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:54:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/13 19:05:35 by mkibous          ###   ########.fr       */
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
	return (1);
}

int	do_inst(char *str, t_stack **a, t_stack **b)
{
	int		j;
	char	**instruction;

	instruction = ft_split(str, '\n');
	if (instruction == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	j = 0;
	free(str);
	while (instruction[j])
	{
		if (ft_instructions(a, b, instruction[j]))
			return (ft_free(instruction), 1);
		j++;
	}
	ft_free(instruction);
	return (0);
}

int	protect(char *str, char *line, int b)
{
	if (b == 1 && str && line && line[0] == '\n')
	{
		free(line);
		return (free (str), 1);
	}
	if (!str)
	{
		if (str)
			free (str);
		if (line)
			free(line);
		return (1);
	}
	return (0);
}

int	get_instructions(t_stack **a, t_stack **b)
{
	char	*str;
	char	*line;
	int		bl;

	bl = 0;
	(1 == 1) && (str = ft__strdup(""), line = get_next_line(0));
	if (protect(str, line, 1) == 1)
		return (1);
	while (line)
	{
		if (str[ft_strlen(str) - 1] == '\n' && line[0] == '\n')
			return (free(str), free(line), 1);
		ft_check(line, &bl);
		str = ft__strjoin(str, line);
		if (protect(str, line, 0) == 1)
			return (1);
		free(line);
		line = get_next_line(0);
	}
	if (!line && str && str[0] != '\0' && str[ft_strlen(str) - 1] != '\n')
		return (free(str), 1);
	if (str && do_inst(str, a, b))
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
	if (l == 0)
		exit(0);
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
	if (ft_lstsize(b) == 0 && ft_chek_if_sorted(a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(0);
}
