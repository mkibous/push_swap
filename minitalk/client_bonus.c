/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:00:34 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/15 05:50:17 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_print(int i)
{
	if (i == SIGUSR1)
	{
		ft_printf("Mesage have been sended");
		exit (0);
	}
}

void	ft_send_char(char c, pid_t	pid)
{
	int		b;

	b = 7;
	while (b >= 0)
	{
		usleep(600);
		if (((c >> b) & 1) == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				(ft_putstr_fd("Error: Verify the PID", 2), exit(1));
		}
		else if (((c >> b) & 1) == 0)
			if (kill(pid, SIGUSR1) == -1)
				(ft_putstr_fd("Error: Verify the PID", 2), exit(1));
		b--;
	}
}

void	ft_send_zero(pid_t pid)
{
	ft_send_char('\0', pid);
	signal(SIGUSR1, &ft_print);
	usleep(5000);
}

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
	pid_t	pid;

	if (arc != 3)
		(ft_putstr_fd("Error: Verify the argument format", 2), exit(1));
	i = 0;
	(1) && (i = 0, pid = ft_pid_check(arv[1]));
	while (arv[2][i])
	{
		ft_send_char(arv[2][i], pid);
		i++;
	}
	ft_send_zero(pid);
}
