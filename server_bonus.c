/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:54 by ahmalman          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:28 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (sig == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (sig == SIGUSR2)
	{
		c = (c << 1) | 0;
	}
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			usleep(350);
			kill(siginfo->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	s11;
	struct sigaction	s12;

	(void)argv;
	if (argc == 1)
	{	
		pid = getpid();
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		s11.sa_flags = SA_SIGINFO;
		s11.sa_sigaction = handler;
		sigemptyset(&s11.sa_mask);
		sigaction(SIGUSR1, &s11, NULL);
		s12.sa_flags = SA_SIGINFO;
		s12.sa_sigaction = handler;
		sigemptyset(&s12.sa_mask);
		sigaction(SIGUSR2, &s12, NULL);
		while (1)
			;
	}
	else
	{
		ft_putstr_fd("Server Cant Work With Any Arguments\n", 1);
	}
}
