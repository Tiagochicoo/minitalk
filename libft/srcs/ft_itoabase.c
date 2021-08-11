/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 08:53:07 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/08 15:37:28 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numdigits(long n, int base)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_itoabase(long n, int base)
{
	char	*rep_str;
	char	*str;
	int		len;
	int		i;

	i = 1;
	len = ft_numdigits(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	rep_str = "0123456789abcdef";
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		i = -1;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = rep_str[(n % base)*i];
		n /= base;
	}
	return (str);
}
