/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:52:59 by kali              #+#    #+#             */
/*   Updated: 2020/12/20 16:56:20 by kali             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return(NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}