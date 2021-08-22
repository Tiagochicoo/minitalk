/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:17:20 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/22 17:36:15 by tpereira         ###   ########.fr       */
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

int	send_string(int pid, char *str)
{
	static char	*string = 0;
	static int	bits = -1;

	if (str)
		string = ft_strdup(str);
	if (!string)
		error(0);
	if (string[++bits / 8])
	{
		if (string[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(pid, SIGUSR2) == -1)
				error(string);
		}
		else if (kill(pid, SIGUSR1) == -1)
			error(string);
		return (0);
	}
	if (!send_null(pid, string))
		return (0);
	free(string);
	return (1);
}

void	handler_sigusr(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = send_string(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("Unexpected server error.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		ft_putstr_fd("Message delivered to server.\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isnumber(argv[1]))
	{
		ft_putstr_fd("usage: ./client [server-pid] [message]\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_string(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
