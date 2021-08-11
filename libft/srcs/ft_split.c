/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 08:59:57 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:14:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	word_count(char *str, char charset)
{
	long long	count;

	count = 0;
	while (*str)
	{
		if (*str != charset)
		{
			++count;
			while (*str && *str != charset)
				++str;
		}
		if (*str != 0)
			str++;
	}
	return (count);
}

static void	ftl_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}

char	**ft_split(char const *str, char charset)
{
	char		**str_arr;
	long long	i;
	char		*from;

	str_arr = (char **)malloc(sizeof(char *)
			* word_count((char *)str, charset) + 1);
	if (!str || !(str_arr))
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != charset)
		{
			from = (char *)str;
			while (*str && *str != charset)
				++str;
			str_arr[i] = (char *)malloc(str - from + 1);
			ftl_strcpy(str_arr[i++], from, (char *)str);
		}
		if (*str != 0)
			++str;
	}
	str_arr[i] = 0;
	return (str_arr);
}
