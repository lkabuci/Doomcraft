//
// Created by redone on 7/27/23.
//

#include "libft.h"

char	*ft_strdup(char *str)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen(str) + 1;
	s = (char *)ft_calloc(sizeof(char) * len);
	i = -1;
	while (++i < len)
		s[i] = str[i];
	return (s);
}