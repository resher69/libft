/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:08:37 by agardet           #+#    #+#             */
/*   Updated: 2021/01/09 15:00:09 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_sep(char *s, char c)
{
	size_t	i;
	size_t	nb_sep;
	size_t	is_separator;

	i = 0;
	nb_sep = 0;
	while (s[i])
	{
		is_separator = 0;
		while ((s[i] == c) && (s[i] != 0))
		{
			is_separator = 1;
			i++;
		}
		while ((s[i] != c) && (s[i] != 0))
			i++;
		if (is_separator == 1 && s[i] != 0)
			nb_sep++;
	}
	return (nb_sep == 0 ? 1 : nb_sep);
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

char		**ft_split(char const *s, char c)
{
	char	**strs_split;
	char	*start;
	char	*s_cpy;
	size_t	i;
	size_t	nb_words;
	int	  found;

	i = 0;
	s_cpy = (char *)s;
	nb_words = count_sep(s_cpy, c);
	//printf("nb vaut :%d\n", nb_words);
	if (!(strs_split = ft_calloc(sizeof(char *), (nb_words + 1))))
		return (NULL);
	if (!s)
		return (NULL);
	while (*s_cpy)
	{
		found = 0;
		while (*s_cpy && *s_cpy == c)
			s_cpy++;
		start = s_cpy;
		while (*s_cpy && *s_cpy != c)
		{
			found = 1;
			s_cpy++;
		}
		if (found == 1)
		{
			if (!(strs_split[i] = strs_len(start, c)))
				return (free_tab(strs_split));
			ft_strncpy(strs_split[i], start, s_cpy - start);
			i++;
		}
	}
	strs_split[i] = NULL;
	return (strs_split);
}


// int main()
// {
// 	char *s = "     issou  42  ";
// 	char **issou;
// 	issou = ft_split(s, ' ');
// 	int i;

// 	i = 0;
// 	while (issou[i])
// 	{
// 		printf("%s\n", issou[i]);
// 		free(issou[i]);
// 		i++;
// 	}
// 	free(issou);
//}

//		clear && gcc -Wall -Wextra -fsanitize=address ft_split.c libft.a && ./a.out