/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:17:20 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/22 18:31:13 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Unexpected error.\n", 2);
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error(str);
		return (0);
	}
	return (1);
}

int	send_sig(int pid, char *str)
{
	static char	*string = 0;
	static int	static_pid = 0;
	static int	bits = -1;

	if (str)
		string = ft_strdup(str);
	if (!string)
		error(0);
	if (pid)
		static_pid = pid;
	if (string[++bits / 8])
	{
		if (string[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(static_pid, SIGUSR2) == -1)
				error(string);
		}
		else if (kill(static_pid, SIGUSR1) == -1)
			error(string);
		return (0);
	}
	if (!send_null(static_pid, string))
		return (0);
	free(string);
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
		ft_putstr_fd("Unexpected server error!\n", 2);
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		ft_putstr_fd("Message delivered to server\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isnumber(argv[1]))
	{
		ft_putstr_fd("usage: ./client [server-pid] [string]\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	send_sig(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
