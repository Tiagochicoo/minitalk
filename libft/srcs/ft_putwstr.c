/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:00:31 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:14:59 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_putwstr() function outputs a wide string to the standard output.
*/

int	ft_putwstr(wchar_t *ws)
{
	int	i;

	i = 0;
	while (ws[i] != '\0')
	{
		ft_putchar(ws[i]);
		i++;
	}
	return (i);
}
