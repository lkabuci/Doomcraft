#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	ls;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		ls = 0;
	else
	{
		if (start == 0)
			ls = ft_strlen(s);
		else
			ls = ft_strlen(s + start - 1);
	}
	if (ls < len)
		len = ls;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
