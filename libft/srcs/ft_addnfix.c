/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnfix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:42:14 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:05:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addnfix(char **str, char fix_char, int len, int side)
{
	char	*fix;
	char	*joined;

	joined = NULL;
	if (len && len != -1)
	{
		fix = ft_strnew(len);
		if (!fix)
			return ;
		ft_memset(fix, fix_char, len);
		if (side == 2)
			joined = ft_strjoin(*str, fix);
		else
			joined = ft_strjoin(fix, *str);
		free(*str);
		free(fix);
		*str = joined;
	}
}
