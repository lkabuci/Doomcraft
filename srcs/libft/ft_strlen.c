//
// Created by redone on 7/27/23.
//

#include "libft.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}
