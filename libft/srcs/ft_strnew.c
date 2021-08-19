/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:45:52 by tpereira          #+#    #+#             */
/*   Updated: 2021/08/19 20:42:13 by tpereira         ###   ########.fr       */
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
		str = (char *)ft_calloc(size, sizeof(*str) * (1));
		return (str);
	}
	return (NULL);
}
