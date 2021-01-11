/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:52:08 by agardet           #+#    #+#             */
/*   Updated: 2021/01/11 17:58:48 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!f || !del || !lst)
		return (NULL);
	new = ft_lstnew(lst);
	while (lst)
	{
		new->content = f(lst->content);
		lst = lst->next;
		ft_lstadd_back(&new, new);
	}
}

