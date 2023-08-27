#include "../includes/libft.h"

int	ft_split_len(char **elements)
{
	int	i;

	i = -1;
	while (elements[++i])
		;
	return (i);
}
