/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:13:50 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/24 10:22:19 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		l;
	va_list	args;

	va_start(args, str);
	i = 0;
	l = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_arg(args, str[i], &l);
		}
		else if (str[i] != '%')
			ft_putchar(str[i], &l);
		i++;
	}
	va_end(args);
	return (l);
}
