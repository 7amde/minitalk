/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:58:55 by ahmalman          #+#    #+#             */
/*   Updated: 2023/09/13 20:33:04 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	invaledprint(int pid)
{
	ft_putstr_fd("This Input Is Invalid (", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(").\n", 1);
	exit(0);
}

void	send(int pid, char c)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (i >= 0)
	{
		if ((c >> i & 1) == 1)
		{
			j = kill(pid, SIGUSR1);
			usleep(150);
		}
		else
		{
			j = kill(pid, SIGUSR2);
			usleep(150);
		}
		usleep(150);
		i--;
	}
	if (j == -1)
		invaledprint(pid);
}

int	checkers(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{	
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		if (checkers(argv[1]) == 0)
		{
			ft_putstr_fd("This Input Is Invalid (", 1);
			ft_putstr_fd(argv[1], 1);
			ft_putstr_fd(").\n", 1);
			return (0);
		}
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send(pid, argv[2][i]);
			i++;
		}
		send(pid, '\0');
		pause();
	}
	else
		ft_putstr_fd("Minitalk Work On 3 Arguments Only.\n", 1);
	return (0);
}
