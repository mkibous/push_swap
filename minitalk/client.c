/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:00:34 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/15 06:36:11 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	ft_pid_check(char *str)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			(ft_putstr_fd("Error: Non-digit detected in PID", 2), exit(1));
		i++;
	}
	pid = ft_atoi(str);
	if (pid == 0)
		(ft_putstr_fd("Error: Verify the PID", 2), exit(1));
	return (pid);
}

int	main(int arc, char **arv)
{
	int		i;
	int		b;
	pid_t	pid;

	if (arc != 3)
		(ft_putstr_fd("Error: Verify the argument format", 2), exit(1));
	(1) && (i = 0, pid = ft_pid_check(arv[1]));
	while (arv[2][i])
	{
		b = 31;
		while (b >= 0)
		{
			usleep(500);
			if (((arv[2][i] >> b) & 1) == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					(ft_putstr_fd("Error: Verify the PID", 2), exit(1));
			}
			else if (((arv[2][i] >> b) & 1) == 0)
				if (kill(pid, SIGUSR1) == -1)
					(ft_putstr_fd("Error: Verify the PID", 2), exit(1));
			b--;
		}
		i++;
	}
}
