/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:52:19 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:08:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		ii = 0;
		while (big[i + ii] == little[ii] && i + ii < len)
		{
			if (little[ii + 1] == 0)
				return ((char *)big + i);
			ii++;
		}
		i++;
	}
	return (NULL);
}
