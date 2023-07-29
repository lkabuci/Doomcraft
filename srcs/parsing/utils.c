//
// Created by redone on 7/28/23.
//

#include "cray.h"

static bool	is_all_spaces(const char *line);

char	*readline(int fd)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_all_spaces(line) == true || ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		return (line);
	}
	return (NULL);
}

static bool	is_all_spaces(const char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (false);
	}
	return (true);
}

bool	is_all_num(char **elements)
{
	int	i;
	int	j;

	i = -1;
	while (elements[++i])
	{
		j = -1;
		while (elements[i][++j])
		{
			if (elements[i][j] < '0' || elements[i][j] > '9')
				return (false);
		}
	}
	return (true);
}

void	skip_till_first_map_line(t_map_info *pInfo)
{
	char	*line;

	while (true)
	{
		line = readline(pInfo->fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, pInfo->ptr_saver) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}