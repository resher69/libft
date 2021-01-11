/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:36:56 by agardet           #+#    #+#             */
/*   Updated: 2021/01/11 15:30:29 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *buffer;

	if (!del || !lst)
		return ;
	buffer = *lst;
	*lst = NULL;
	while (buffer->next)
	{
		buffer = buffer->next;
		del(buffer->content);
		free(buffer);
	}
}
