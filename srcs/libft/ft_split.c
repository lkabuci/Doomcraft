//
// Created by redone on 7/28/23.
//

#include "libft.h"

static void	*free_all(char **tab, int i);
static size_t	count_strings(char *str, char c);
static char	*allocate_word(char *str, char c);
static size_t	ft_strlen_sep(char *str, char c);

char	**ft_split(char *s, char c)
{
	char	**str;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	str = (char **) ft_calloc(sizeof(char *) * (count_strings((char *)s, c) + 1));
	while (*(char *)s)
	{
		while (*(char *)s && *(char *)s == c)
			s++;
		if (*(char *)s)
		{
			*(str + i) = allocate_word((char *)s, c);
			if (!*(str + i))
				return (free_all(str, i));
			i++;
		}
		while (*(char *)s && *(char *)s != c)
			s++;
	}
	*(str + i) = 0;
	return (str);
}

static void	*free_all(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

static size_t	count_strings(char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		while (*(str + i) && *(str + i) == c)
			i++;
		if (*(str + i))
			count++;
		while (*(str + i) && *(str + i) != c)
			i++;
	}
	return (count);
}

static size_t	ft_strlen_sep(char *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

static char	*allocate_word(char *str, char c)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = (char *)ft_calloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		*(word + i) = *(str + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}


