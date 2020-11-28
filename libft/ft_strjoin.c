/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:07:18 by agardet           #+#    #+#             */
/*   Updated: 2020/11/27 20:25:46 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*res;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	res = ft_memset(res, 0, total_len);
	ft_strcat(res, (char *)s1);
	ft_strcat(res, (char *)s2);
	res[total_len] = 0;
	return (res);
}