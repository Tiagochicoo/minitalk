/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:12:31 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/19 19:35:08 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(int c)
{
	char	*str;
	int		isnumber;

	isnumber = 0;
	str = ft_itoa(c);
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
