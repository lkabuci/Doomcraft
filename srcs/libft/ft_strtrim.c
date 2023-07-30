//
// Created by redone on 7/29/23.
//

#include "libft.h"

static int	is_char_in(char c, char *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

static char	*prefix_trim(char *str, char *sep)
{
	while (*str)
	{
		if (is_char_in(*str, sep))
			str++;
		else
			return (str);
	}
	return (str);
}

static char	*suffix_trim(char *str, char *sep)
{
	char	*buffer;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > 0)
	{
		if (is_char_in(str[len], sep))
			len--;
		else
			break ;
	}
	buffer = (char *) malloc(sizeof(char) * (len + 2));
	if (!buffer)
		return (0);
	while (i < len + 1)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*buffer;
	char	*str;
	char	*sep;

	if (!s1 || !set)
		return (0);
	str = (char *)s1;
	sep = (char *)set;
	str = prefix_trim(str, sep);
	if (!*str)
	{
		buffer = (char *)malloc(sizeof(char));
		*buffer = '\0';
	}
	else
		buffer = suffix_trim(str, sep);
	return (buffer);
}