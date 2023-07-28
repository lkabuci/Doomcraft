//
// Created by redone on 7/27/23.
//

#include "libft.h"

char	*ft_strchr(char *str)
{
	while (*str != '\n')
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (str);
}
