/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:45:52 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:08:56 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_strnew() allocates with malloc(3) and returns a fresh
** string ending with '\0'. Each character of the string is initialized at
** '\0'. If the allocation fails, the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(*str) * (1));
		if (str)
		{
			ft_memset(str, '\0', (1));
			return (str);
		}
	}
	else if (size)
	{
		str = (char *)malloc(sizeof(*str) * (size + 1));
		if (str)
		{
			ft_memset(str, '\0', (size + 1));
			return (str);
		}
	}
	return (NULL);
}
