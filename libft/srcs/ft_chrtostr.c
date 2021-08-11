/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:43:02 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 21:25:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strdup mallocs a new string from a char
*/

#include "libft.h"

char	*ft_chrtostr(char c)
{
	char	*str;

	str = malloc(sizeof(*str) * 2);
	if (str)
	{
		str[0] = c;
		str[1] = '\0';
	}
	return (str);
}
