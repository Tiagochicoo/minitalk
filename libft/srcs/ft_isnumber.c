/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:12:31 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/19 20:19:40 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str)
{
	int		isnumber;

	isnumber = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			isnumber = 1;
		else
			return (0);
		str++;
	}	
	return (isnumber);
}
