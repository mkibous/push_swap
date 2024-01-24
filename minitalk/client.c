/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:00:34 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/13 17:35:20 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int main(int arc , char **arv)
{
    int i = 0;
    int b;

    if(arc != 3)
        return(0);
    pid_t pid = ft_atoi(arv[1]);
    while (arv[2][i])
    {
        b = 31;
        while (b >= 0)
        {
            if(((arv[2][i] >> b) & 1) == 1)
                kill(pid, SIGUSR2);
            else if(((arv[2][i] >> b) & 1) == 0)
                kill(pid, SIGUSR1);
            b--;
            usleep(400);
        }
        i++;
    }
    
    ft_printf("%d", pid);
}
