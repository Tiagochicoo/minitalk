/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:17:20 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/17 18:21:18 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	usage(void)
{
	ft_putstr_fd("usage: ./client [server-pid] [message]\n", 1);
	exit(1);
}

void	success(int sig)
{
	(void)sig;
	ft_putstr_fd("Message received by server.\n", 1);
}

void	error(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Unexpected error",1);
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *str)
{
	static int	i;

	i = 0;
	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error(str);
		return (0);
	}
	return (1);
}

int	send_sig(char *str, int pid)
{
	static char	*string;
	static int	s_pid;
	static int	bits;

	string = 0;
	s_pid = 0;
	bits = -1;
	if (str)
		string = ft_strdup(str);
	if (!string)
		error(0);
	if (pid)
		s_pid = pid;
	if (string[++bits / 8])
	{
		if (string[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				error(string);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			error(string);
		return (0);
	}
	if (!send_null(s_pid, string))
		return (0);
	free (string);
	return (1);
}

void	handle_sigusr(int sig)
{
	int	end;

	end = 0;
	if (sig == SIGUSR1)
		end = send_sig(0, 0);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("Unexpected error", 2);
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		ft_putstr_fd("Message sent", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int	isdigit;
	int	pid;
	
	pid = ft_atoi(argv[1]);
	isdigit = ft_isdigit(pid);
	if (argc != 3 || isdigit == 1)
		usage();
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	send_sig(argv[2], ft_atoi(argv[1]));
	return (0);
}