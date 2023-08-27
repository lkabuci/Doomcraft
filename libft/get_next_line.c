#include "../includes/libft.h"

static char	*ft__strjoin(char **s1, char **s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	rsize;

	if (!*s1)
	{
		*s1 = (char *)malloc(1 * sizeof(char));
		*s1[0] = '\0';
	}
	if (!*s1 || !*s2)
		return (NULL);
	rsize = (ft_strlen(*s1) + ft_strlen(*s2) + 1);
	res = (char *)malloc(rsize * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while ((*s1)[++i])
		res[i] = (*s1)[i];
	j = -1;
	while ((*s2)[++j])
		res[i++] = (*s2)[j];
	res[i] = '\0';
	free(*s1);
	return (res);
}

static char	*ft_read_line(int fd, char *reserve)
{
	char	*buff;
	int		check;

	buff = malloc((1 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	check = 1;
	while (check != 0 && ft_strchr(reserve, '\n') == NULL)
	{
		check = read(fd, buff, 1);
		if (check == -1)
			return (free(buff), NULL);
		buff[check] = '\0';
		reserve = ft__strjoin(&reserve, &buff);
	}
	free(buff);
	return (reserve);
}

static char	*ft_truncate_left(char *str)
{
	int		len;
	char	*res;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	res = malloc((len + 2) * sizeof(char));
	if (!res)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		res[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		res[len] = str[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

static char	*ft_truncate_right(char **str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
	{
		free(*str);
		return (NULL);
	}
	len = i + 1;
	while ((*str)[len])
		len++;
	res = malloc((len - i) * sizeof(char));
	if (!res)
		return (NULL);
	len = i + 1;
	i = 0;
	while ((*str)[len])
		res[i++] = (*str)[len++];
	res[i] = '\0';
	free(*str);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*result;

	reserve = NULL;
	if (fd < 0)
		return (0);
	reserve = ft_read_line(fd, reserve);
	if (!reserve)
		return (NULL);
	result = ft_truncate_left(reserve);
	reserve = ft_truncate_right(&reserve);
	free(reserve);
	return (result);
}
