/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:29:36 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/10/16 18:30:43 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cray.h"

void			parse_elements(t_map_info *info);
void			fill_elements(mlx_t *mlx, t_map_info *pInfo, char *key,
					char *value);
void			parse_map(t_map_info *pInfo);
void			get_map_dimensions(t_map_info *pInfo);
void			fill_map(t_map_info *pInfo);

void	parsing(t_seer *seer, const char *filename)
{
	check_filename(filename);
	seer->map_info.fd = open(filename, O_RDONLY);
	if (seer->map_info.fd == -1)
		fatal(ERR_OPEN);
	parse_elements(&seer->map_info);
	get_map_dimensions(&seer->map_info);
	close(seer->map_info.fd);
	seer->map_info.fd = open(filename, O_RDONLY);
	parse_map(&seer->map_info);
	close(seer->map_info.fd);
	free(seer->map_info.ptr_saver);
}

void	parse_elements(t_map_info *info)
{
	int		i;
	char	**elements;
	char	*line;

	i = -1;
	while (++i < NBROF_ELEMENTS)
	{
		line = readline(info->fd);
		if (line == NULL)
			break ;
		elements = ft_split(line, SPACES);
		if (ft_split_len(elements) != 2)
			fatal(ERR_ELEMENT);
		fill_elements(info->seer->mlx, info, elements[0], elements[1]);
		free(line);
		free_array(elements);
	}
	info->ptr_saver = readline(info->fd);
}

void	fill_elements(mlx_t *mlx, t_map_info *pInfo, char *key, char *value)
{
	if (!ft_strcmp(key, "NO") && pInfo->north_image == NULL)
		pInfo->north_image = get_texture(mlx, value);
	else if (!ft_strcmp(key, "SO") && pInfo->south_image == NULL)
		pInfo->south_image = get_texture(mlx, value);
	else if (!ft_strcmp(key, "WE") && pInfo->west_image == NULL)
		pInfo->west_image = get_texture(mlx, value);
	else if (!ft_strcmp(key, "EA") && pInfo->east_image == NULL)
		pInfo->east_image = get_texture(mlx, value);
	else if (!ft_strcmp(key, "F") && pInfo->floor_color == -1)
		pInfo->floor_color = get_rgb(value);
	else if (!ft_strcmp(key, "C") && pInfo->ceil_color == -1)
		pInfo->ceil_color = get_rgb(value);
	else
		fatal(ERR_DUPLICATED);
}
