static size_t	ft_count_words(char *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while ((s[i] == c) && (s[i] != 0))
			i++;
		while ((s[i] != c) && (s[i] != 0))
			i++;
		sep_count++;
	}
	return (word_count);
}

static char	ft_free_split(char **s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

static char	*ft_get_next_word(char *s, char c)
{
	size_t	i;
	char	*line;

	i = 0;
	while ((s[i] != c) && (s[i] != 0))
		i++;
	if (!(line = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	line = ft_strncpy(line, s, i);
	return (line);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;
	char	**strs_split;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words((char *)s, c);
	if (!(strs_split = ft_calloc(nb_words + 1, sizeof(char *))))
		return (NULL);
	while ((*s == c) && (*s != 0))
		s++;
	while (i < nb_words)
	{
		if (!(strs_split[i] = ft_get_next_word((char *)s, c)))
		{
			ft_free_split(strs_split);
			return (strs_split);
		}
		while ((*s != c) && (*s != 0))
			s++;
		while ((*s == c) && (*s != 0))
			s++;
		i++;
	}
	if (i > 1)
		strs_split[i - 1] = NULL;
	return (strs_split);
}
