#include "../../includes/cray.h"

void	get_map_dimensions(t_map_info *pInfo)
{
	char	*line;
	int		line_len;
	char	*rest_map;

	if (!pInfo->ptr_saver)
		fatal("Invalid map_info !!");
	pInfo->map_width = ft_strlen(pInfo->ptr_saver) - 1;
	while (true)
	{
		line = get_next_line(pInfo->fd);
		if (line == NULL || ft_strcmp(line, "\n") == 0)
			break ;
		line_len = ft_strlen(line) - 1;
		if (line_len > pInfo->map_width)
			pInfo->map_width = line_len;
		pInfo->map_height++;
		free(line);
	}
	free(line);
	rest_map = readline(pInfo->fd);
	if (rest_map != NULL)
	{
		free(rest_map);
		fatal("elements after map_info");
	}
}

void	parse_map(t_map_info *pInfo)
{
	skip_till_first_map_line(pInfo);
	fill_map(pInfo);
	check_map(pInfo, pInfo->map_2d);
}

void	fill_map(t_map_info *pInfo)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_strdup(pInfo->ptr_saver);
	pInfo->map_2d = ft_calloc(sizeof(char *) * (pInfo->map_height + 1));
	while (true)
	{
		pInfo->map_2d[i] = ft_calloc(sizeof(char) * (pInfo->map_width + 1));
		ft_memset(pInfo->map_2d[i], ' ', pInfo->map_width);
		ft_memcpy(pInfo->map_2d[i], line, ft_strlen(line) - 1);
		free(line);
		line = readline(pInfo->fd);
		if (line == NULL)
			break ;
		i++;
	}
}
