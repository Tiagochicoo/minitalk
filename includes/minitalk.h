/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:35:47 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/11 20:12:51 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# include <stdbool.h>
# define MINITALK_H

# define BUFFER 1024

typedef struct 	s_minitalk
{
	char	message[BUFFER];
	int		bit;
	int		byte;
	bool	received;
	bool	overflow;
}				t_minitalk;

t_minitalk	print = {{0}, 1 << 6, 0, false, false};

void		error(char *error_str);

#endif