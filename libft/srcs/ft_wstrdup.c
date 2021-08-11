/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:34:25 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:06:37 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** The ft_wstrdup() function allocates sufficient memory for a copy of the
** wide string wstr, does the copy, and returns a pointer to it.  The pointer
** may subsequently be used as an argument to the function free(3). If
** insufficient memory is available, NULL is returned
*/

wchar_t	*ft_wstrdup(const wchar_t *wstr)
{
	size_t	len;
	wchar_t	*wstr_copy;
	int		i;

	len = ft_wstrlen(wstr);
	wstr_copy = malloc(sizeof(*wstr_copy) * (len + 1));
	if (wstr_copy)
	{
		i = 0;
		while (wstr[i] != L'\0')
		{
			wstr_copy[i] = wstr[i];
			i++;
		}
		wstr_copy[i] = L'\0';
	}
	return (wstr_copy);
}
