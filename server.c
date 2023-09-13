/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:54 by ahmalman          #+#    #+#             */
/*   Updated: 2023/09/13 20:35:47 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int	i;
	static char	c;

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
		i = 0;
		c = 0;
	}
}

int	main(int argc, char**argv)
{
	pid_t	pid;

	(void)argv;
	if (argc == 1)
	{	
		pid = getpid();
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		ft_putstr_fd("Server Is Running \nWaiting For A Signel \n", 1);
		while (1)
			;
	}
	else
	{
		ft_putstr_fd("Server Cant Work With Any Arguments\n", 1);
	}
}
