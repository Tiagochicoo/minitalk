/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:02:09 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 18:27:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next1;
	t_list	*next2;

	if (!lst)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	next1 = lst->next;
	next2 = new;
	while (1 == 1)
	{
		if (next1 == NULL)
			break ;
		next2->next = ft_lstnew((*f)(next1->content));
		if (!next2->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		next1 = next1->next;
		next2 = next2->next;
	}
	return (new);
}
