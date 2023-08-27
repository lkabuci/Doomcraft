#include "../includes/libft.h"

char	*ft_strdup(char *str)
{
	char	*buffer;
	size_t	str_len;

	str_len = ft_strlen(str);
	buffer = ft_calloc(sizeof(char) * (str_len + 1));
	ft_memcpy(buffer, str, str_len);
	return (buffer);
}
