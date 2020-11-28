/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:02:49 by agardet           #+#    #+#             */
/*   Updated: 2020/11/27 19:13:57 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dst;
if ((dst = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + 1)) == NULL)
	return (NULL);
ft_strcpy(dst, s1);
return (dst);
} 