/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:27:11 by zyasa             #+#    #+#             */
/*   Updated: 2023/04/05 17:27:14 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(const char *message, const int exit_code)
{
	ft_printf("%sError:%s %s\n", RED, DEFAULT, message);
	exit(exit_code);
}

int	convert_pid(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

void	trans(unsigned char ch, const int pid, const int bit)
{
	if (bit == 0)
		return ;
	if (ch >= bit)
	{
		kill(pid, SIGUSR1);
		ch -= bit;
	}
	else
		kill(pid, SIGUSR2);
	usleep(100);
	trans(ch, pid, bit / 2);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
		error("invalid number of parameters", 1);
		pid = convert_pid(av[1]);
	if (pid == -1)
		error("pid must be a positive number", 2);
	i = 0;
	while (av[2][i])
	{
		trans(av[2][i], pid, 128);
		i++;
	}
	return (0);
}
