//
// Created by redone on 7/27/23.
//

#include "../../includes/cray.h"

void parse_elements(t_map_info *info);
void fill_elements(mlx_t *mlx, t_map_info *pInfo, char *key, char *value);
mlx_image_t *get_texture(mlx_t *pMlx, char *path);
long get_rgb(char *value);
u_int32_t get_color(const int *rgb);
bool check_commas(const char *str);
void parse_map(t_map_info *pInfo);
void get_map_dimensions(t_map_info *pInfo);
void fill_map(t_map_info *pInfo);

void parsing(t_seer *seer, const char *filename)
{
	check_filename(filename);
	seer->map_info.fd = open(filename, O_RDONLY);
	if (seer->map_info.fd == -1)
		fatal("Can't open the file");
	parse_elements(&seer->map_info);
	get_map_dimensions(&seer->map_info);
	close(seer->map_info.fd);
	seer->map_info.fd = open(filename, O_RDONLY);
	parse_map(&seer->map_info);
	close(seer->map_info.fd);
	free(seer->map_info.ptr_saver);
}

void parse_elements(t_map_info *info)
{
	int i;
	char **elements;
	char *line;
	i = -1;
	while (++i < NBROF_ELEMENTS)
	{
		line = readline(info->fd);
		if (line == NULL)
			break;
		elements = ft_split(line, SPACES);
		if (ft_split_len(elements) != 2)
			fatal("Invalid map_info elements");
		fill_elements(info->seer->mlx, info, elements[0], elements[1]);
		free(line);
		free_array(elements);
	}
	info->ptr_saver = readline(info->fd);
}

void get_map_dimensions(t_map_info *pInfo)
{
	char *line;
	int line_len;
	char *rest_map;
	if (!pInfo->ptr_saver)
		fatal("Invalid map_info !!");
	pInfo->map_width = ft_strlen(pInfo->ptr_saver) - 1;
	while (true)
	{
		line = get_next_line(pInfo->fd);
		if (line == NULL || ft_strcmp(line, "\n") == 0)
			break;
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

void parse_map(t_map_info *pInfo)
{
	skip_till_first_map_line(pInfo);
	fill_map(pInfo);
	check_map(pInfo, pInfo->map_2d);
}

void fill_map(t_map_info *pInfo)
{
	char *line;
	int i;
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
			break;
		i++;
	}
}

void fill_elements(mlx_t *mlx, t_map_info *pInfo, char *key, char *value)
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
		fatal("duplicated or invalid element");
}

long get_rgb(char *value)
{
	int i;
	int *rgb_arr;
	char **elements;
	u_int32_t color;
	i = -1;
	rgb_arr = ft_calloc(sizeof(int) * 3);
	elements = ft_split(value, ",");
	if (ft_split_len(elements) != 3 || is_all_num(elements) == false
			|| check_commas(value) == false)
		fatal("invalid rgb");
	while (elements[++i])
	{
		if (ft_strlen(elements[i]) > 3)
			fatal("invalid rgb");
		rgb_arr[i] = ft_atoi(elements[i]);
		if (rgb_arr[i] > 255 || rgb_arr[i] < 0)
			fatal("invalid rgb");
	}
	color = get_color(rgb_arr);
	free_array(elements);
	free(rgb_arr);
	return (color);
}

bool check_commas(const char *str)
{
	int i;
	int nbrof_commas;
	i = -1;
	nbrof_commas = 0;
	if (str == NULL)
		return (false);
	while (str[++i])
	{
		if (str[i] == ',')
			nbrof_commas++;
	}
	return (nbrof_commas == 2);
}

u_int32_t get_color(const int *rgb)
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	red = rgb[0];
	green = rgb[1];
	blue = rgb[2];
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

mlx_image_t *get_texture(mlx_t *pMlx, char *path)
{
	mlx_image_t *image;
	mlx_texture_t *texture;
	texture = mlx_load_png(path);
	if (texture == NULL)
		fatal(mlx_strerror(mlx_errno));
	image = mlx_texture_to_image(pMlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(image, CUBE_SIZE, CUBE_SIZE);
	return (image);
}
