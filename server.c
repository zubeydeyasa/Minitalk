/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:27:27 by zyasa             #+#    #+#             */
/*   Updated: 2023/04/05 17:27:31 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(const int sig)
{
	static int		total;
	static double	i = 0.5;

	i *= 2;
	if (sig == SIGUSR1)
		total += (128 / i);
	if (i == 128)
	{
		ft_printf("%c", total);
		total = 0;
		i = 0.5;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		;
	return (0);
}
