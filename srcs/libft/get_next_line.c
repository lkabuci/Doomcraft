//
// Created by redone on 7/27/23.
//

#include "libft.h"

static char	*read_line(int fd, char **stash, char *buffer);
static char	*join_line(int nl_position, char **stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	line = read_line(fd, &stash, buffer);
	free_ptr(&buffer);
	return (line);
}

char	*join_line(int nl_position, char **stash)
{
	char	*line;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
	{
		if (**stash == '\0')
		{
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		line = *stash;
		*stash = NULL;
		return (line);
	}
	tmp = ft_substr(*stash, nl_position, BUFFER_SIZE);
	line = *stash;
	line[nl_position] = 0;
	*stash = tmp;
	return (line);
}

char	*read_line(int fd, char **stash, char *buffer)
{
	ssize_t	readed;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*stash);
	tmp = NULL;
	readed = 0;
	while (!nl)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			return (join_line(readed, stash));
		buffer[readed] = 0;
		tmp = ft_strjoin(*stash, buffer);
		free_ptr(stash);
		*stash = tmp;
		nl = ft_strchr(*stash);
	}
	return (join_line(nl - *stash + 1, stash));
}
