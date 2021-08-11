/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:48:31 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:25:56 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	i = 0;
	while (i < n && src2[i] != (unsigned char)c)
	{
		dest2[i] = src2[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		dest2[i] = src2[i];
		i++;
		return (&dest2[i]);
	}
}
