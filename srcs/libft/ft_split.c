//
// Created by redone on 7/28/23.
//

#include "libft.h"

static int	is_sep(char c, char *charset);
static int	count_strings(char *str, char *charset);
static int	ft_strlen_sep(char *str, char *charset);
static char	*allocate_word(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		i;

	i = 0;
	strings = ft_calloc(sizeof(char *) * (count_strings(str, charset) + 1));
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			*(strings + i) = allocate_word(str, charset);
			i++;
		}
		while (*str && !is_sep(*str, charset))
			str++;
	}
	*(strings + i) = 0;
	return (strings);
}

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (*(charset + i))
	{
		if (c == *(charset + i))
			return (1);
		i++;
	}
	return (0);
}

static int	count_strings(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		while (*(str + i) && is_sep(*(str + i), charset))
			i++;
		if (*(str + i))
			count++;
		while (*(str + i) && !is_sep(*(str + i), charset))
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*(str + i) && !is_sep(*(str + i), charset))
		i++;
	return (i);
}

static char	*allocate_word(char *str, char *charset)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, charset);
	word = (char *)ft_calloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		*(word + i) = *(str + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}
