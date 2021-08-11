/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:18:08 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:26:18 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	unsigned const char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned const char *)src;
	if ((dest2 != NULL) || (src2 != NULL))
	{
		while (n)
		{
			*(dest2++) = *(src2++);
			--n;
		}
	}
	return (dest);
}
