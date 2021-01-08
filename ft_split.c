/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:08:37 by agardet           #+#    #+#             */
/*   Updated: 2021/01/08 11:28:59 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c)
{
	size_t	i;
	size_t	nb_sep;

	i = 0;
	nb_sep = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] + 1 != c)
			nb_sep++;
		i++;
	}
	return (nb_sep);
}

static size_t	is_separator(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static char		*strs_len(char *s, char c)
{
	size_t	i;
	char	*str_calloc;

	i = 0;
	while (s[i] != c)
		i++;
	if (!(str_calloc = ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	return (str_calloc);
}

char			**ft_split(char const *s, char c)
{
	char	**strs_split;
	char	*start;
	char	*s_cpy;
	size_t	i;
	size_t	nb_words;

	i = 0;
	s_cpy = (char *)s;
	nb_words = count_words(s_cpy, c);
	if (!(strs_split = ft_calloc(sizeof(char),
						(nb_words * ft_strlen(strs_len((char *)s, c))))))
		return (NULL);
	while (*s_cpy)
	{
		while (*s_cpy && is_separator(*s_cpy, c))
			s_cpy++;
		start = s_cpy;
		while (*s_cpy && !is_separator(*s_cpy, c))
			s_cpy++;
		strs_split[i] = strs_len(start, c);
		ft_strncpy(strs_split[i], start, s_cpy - start);
		if (start != s_cpy)
			i++;
	}
	strs_split[i] = NULL;
	return (strs_split);
}
