/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:08:37 by agardet           #+#    #+#             */
/*   Updated: 2021/01/15 14:51:34 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_sep(const char *s, char c)
{
	size_t	i;
	size_t	nb_sep;
	char	*s_cpy;

	s_cpy = (char *)s;
	i = 0;
	nb_sep = 0;
	while (s_cpy[i])
	{
		while ((s_cpy[i] == c) && (s_cpy[i]))
			i++;
		while ((s_cpy[i] != c) && (s_cpy[i]))
			i++;
		if (s_cpy[i] == c && (s_cpy[i]))
			nb_sep++;
		if (s_cpy[i - 1] != c && (s_cpy[i] == 0))
			nb_sep++;
	}
	return (nb_sep);
}

static char		*strs_len(const char *s, char c)
{
	size_t	i;
	char	*str_calloc;

	i = 0;
	while ((s[i] != c) && s[i])
		i++;
	if (!(str_calloc = ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	return (str_calloc);
}

static char		**free_tab(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strs_split;
	char	*start;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(strs_split = ft_calloc(sizeof(char *), (count_sep(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		if (!(strs_split[i] = strs_len(start, c)))
			return (free_tab(strs_split));
		ft_strncpy(strs_split[i], start, s - start);
		if (start != s)
			i++;
	}
	strs_split[i] = NULL;
	return (strs_split);
}
