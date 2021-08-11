/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:19:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:29:12 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ftl_swap(char *str, size_t i)
{
	char	temp;
	size_t	j;
	size_t	n;

	j = 0;
	n = i;
	while (j < ((n + 1) / 2))
	{
		temp = str[j];
		str[j++] = str[i];
		str[i--] = temp;
	}
	str[n + 1] = 0;
	return (str);
}

static int	count_int(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 1;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ftl_malloc(long j, int n)
{
	char	*str;

	if (n < 0)
		str = malloc(count_int(j) + 2);
	else
		str = malloc(count_int(j) + 1);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	j;

	i = 0;
	j = n;
	str = ftl_malloc(j, n);
	if (!str)
		return (NULL);
	if (n < 0)
		j *= -1;
	if (j == 0)
	{
		str[i] = '0';
		return (ftl_swap(str, i));
	}
	str[i++] = 0;
	while (j != 0)
	{
		str[i++] = (j % 10) + '0';
		j /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	return (ftl_swap(str, i - 1));
}
