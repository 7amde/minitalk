/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:58:55 by ahmalman          #+#    #+#             */
/*   Updated: 2023/09/11 18:23:52 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char c)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (i >= 0)
	{
		if ((c >> i & 1) == 1)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		usleep(150);
		i--;
	}
	if (j == -1)
	{
		ft_putstr_fd("This Input Is Invalid (", 1);
		ft_putnbr_fd(pid, 1);
		ft_putstr_fd(").\n", 1);
		exit(0);
	}
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

void	done(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("The Server Recieved The Signal\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

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
			send(pid, argv[2][i++]);
		send(pid, '\0');
		signal(SIGUSR1, done);
		pause();
	}
	else
		ft_putstr_fd("Minitalk Work On 3 Argments Only.\n", 1);
	return (0);
}
