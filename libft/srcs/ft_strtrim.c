/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:40:35 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:07:12 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	from;
	size_t	to;

	if (s1 == 0)
		return (NULL);
	from = 0;
	to = ft_strlen(s1);
	while (is_set(set, s1[from]) && s1[from])
		from++;
	while (is_set(set, s1[to - 1]) && from < to)
		to--;
	s2 = (char *)malloc(sizeof(*s1) * (to - from + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (from < to)
	{
		s2[i] = s1[from];
		from++;
		i++;
	}
	s2[i++] = '\0';
	return (s2);
}
