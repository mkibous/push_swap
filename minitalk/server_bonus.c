/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:18:42 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/15 05:57:48 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_handle_unicode(int *i, unsigned char c)
{
	if (*i == 8)
	{
		if (c < 192)
			return (1);
		else if (c >= 192 && c < 224)
			return (2);
		else if (c >= 224 && c < 240)
			return (3);
		else if (c == 240)
			return (4);
	}
	return (0);
}

void	ft_print(unsigned char c, int *i, int b)
{
	static char		*str;
	static int		j = 0;
	static int		k = 0;

	if (b == 1)
	{
		if (str)
			free(str);
		(1) && (str = NULL, j = 0, k = 0, c = 0, *i = 0);
	}
	if (*i == 8 && j == 0)
	{
		j = ft_handle_unicode(i, c);
		str = (char *)malloc(j + 1);
		if (str == NULL)
			exit(1);
		str[j] = '\0';
	}
	if (*i == 8 && k < j)
		(1) && (str[k] = c, c = 0, *i = 0, k++);
	if (k > 0 && k == j)
		(1) && (ft_printf("%s", str), k = 0, j = 0, free(str), str = NULL);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t			clientpid = 0;
	pid_t					curentpid;
	static int				i = 0;
	static unsigned char	c;
	int						b;

	b = 0;
	if (clientpid == 0)
		clientpid = info->si_pid;
	(1) && (context = NULL, curentpid = info->si_pid);
	if (curentpid != clientpid)
		(1) && (clientpid = curentpid, c = 0, i = 0, b = 1);
	ft_print(c, &i, b);
	if (signum == SIGUSR1)
		(1) && (c = (c << 1 | 0), i++);
	else if (signum == SIGUSR2)
		(1) && (c = (c << 1 | 1), i++);
	if (i == 8 && c == '\0')
	{
		usleep(500);
		if (kill(curentpid, SIGUSR1) == -1)
			exit(1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	pid = getpid();
	if (pid == 0)
		return (0);
	ft_printf("Process ID: %d\n", pid);
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
			(ft_printf("Error in signal handler"), exit(1));
	}
	return (0);
}
