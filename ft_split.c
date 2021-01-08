/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:08:37 by agardet           #+#    #+#             */
/*   Updated: 2021/01/08 16:43:33 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			i++;
		s++;
	}
	return (i);
}

static char		*strs_len(char *s, char c)
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
	free(strs[i]);
	free(strs);
	return (NULL);
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
	if (!(strs_split = ft_calloc(sizeof(char *), (nb_words + 1))))
		return (NULL);
	if (!s)
		return (NULL);
	while (*s_cpy)
	{
		while (*s_cpy && *s_cpy == c)
			s_cpy++;
		start = s_cpy;
		while (*s_cpy && *s_cpy != c)
			s_cpy++;
		if (start == s_cpy)
		{
			strs_split[i] = NULL;
			return (strs_split);
		}
		if (!(strs_split[i] = strs_len(start, c)))
			return (free_tab(strs_split));
		ft_strncpy(strs_split[i], start, s_cpy - start);
		if (start != s_cpy)
			i++;
	}
	strs_split[i] = NULL;
	return (strs_split);
}

/*
int main()
{
	char *s = "  tripouille  42  ";
	char **issou ;
	issou = ft_split(s, ' ');
	int i;

	i = 0;
	while (issou[i])
	{
		printf("%s\n", issou[i]);
		free(issou[i]);
		i++;
	}
	free(issou);
	while (1);
}
*/
//		clear && gcc -Wall -Wextra -fsanitize=address ft_split.c libft.a && ./a.out