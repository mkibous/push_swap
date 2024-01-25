/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:18:42 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/25 04:21:51 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t	clientpid = 0;
	pid_t			curentpid;
	static int		i = 0;
	static int		c = 0;

	if (clientpid == 0)
		clientpid = info->si_pid;
	context = NULL;
	curentpid = info->si_pid;
	if (curentpid != clientpid)
		(1 == 1) && (clientpid = curentpid, c = 0, i = 0);
	if (signum == SIGUSR1)
	{
		c = (c << 1 | 0);
		i++;
	}
	else if (signum == SIGUSR2)
	{
		c = (c << 1 | 1);
		i++;
	}
	if (i == 32 && clientpid == info->si_pid)
		(1 == 1) && (ft_printf("%c", c), i = 0, c = 0);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up signal handler");
		exit(1);
	}
    while (1)
    {
        usleep(500);
    }
	return (EXIT_SUCCESS);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>
// #include "minitalk.h"

// void signal_handler(int signum, siginfo_t *info, void *context)
// {
//     static pid_t clientpid = 0;
//     pid_t curentpid;
//     static int i = 0;
//     static int c = 0;

//     if (clientpid == 0)
//         clientpid = info->si_pid;
//     context = NULL;
//     curentpid = info->si_pid;

//     if (curentpid != clientpid)
//     {
//         clientpid = curentpid;
//         c = 0;
//         i = 0;
//     }

//     if (signum == SIGUSR1)
//     {
//         c = (c << 1 | 0);
//         i++;
//     }
//     else if (signum == SIGUSR2)
//     {
//         c = (c << 1 | 1);
//         i++;
//     }

//     if (i == 32 && clientpid == info->si_pid)
//     {
//         ft_printf("%c", c);
//         i = 0;
//         c = 0;
//     }
// }

// int main(void)
// {
//     struct sigaction sa;
//     pid_t pid;

//     sa.sa_flags = SA_SIGINFO;
//     sa.sa_sigaction = signal_handler;

//     pid = getpid();
//     ft_printf("Process ID: %d\n", pid);

//     if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
//     {
//         perror("Error setting up signal handler");
//         exit(EXIT_FAILURE);
//     }

//     while (1)
//     {
//         // Add a sleep or pause to avoid consuming too much CPU
//         sleep(1);
//     }

//     return (EXIT_SUCCESS);
// }
