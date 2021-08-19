/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:17:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/19 21:50:11 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Unexpected error",2);
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
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
	static char	*str;

	c = 0xFF;
	bits = 0;
	*str = 0;
	(void)context;
	if (sig == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (sig == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			str = ft_addchartostr(str, c);
		else
			str = print(str);
		bits = 0;
		c = 0xFF;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		error(info->si_pid, str);
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
