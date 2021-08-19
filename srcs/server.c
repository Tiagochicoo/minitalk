/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:17:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/19 17:51:00 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Unexpected error",2);
	kill(pid, SIGUSR2);
	exit(1);
}

char*	print(char *str)
{
	ft_putstr_fd(str, 1);
	free(str);
	return (NULL);
}

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits;
	static int	pid;
	static char	*str;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (sig == SIGUSR1)
		c ^= 0x80 >> bits;
	if (sig == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			str = ft_strjoin(str, ft_chrtostr(c));
		else
			str = print(str);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		error(pid, str);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = block_mask;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (true)
		pause();
	
	return (0);
}
