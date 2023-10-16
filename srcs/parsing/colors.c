/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:29:29 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/10/16 18:29:30 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cray.h"

long	get_rgb(char *value)
{
	int				i;
	int				*rgb_arr;
	char			**elements;
	unsigned int	color;

	i = -1;
	rgb_arr = ft_calloc(sizeof(int) * 3);
	elements = ft_split(value, ",");
	if (ft_split_len(elements) != 3 || is_all_num(elements) == false
		|| check_commas(value) == false)
		fatal(ERR_RGB);
	while (elements[++i])
	{
		if (ft_strlen(elements[i]) > 3)
			fatal(ERR_RGB);
		rgb_arr[i] = ft_atoi(elements[i]);
		if (rgb_arr[i] > 255 || rgb_arr[i] < 0)
			fatal(ERR_RGB);
	}
	color = get_color(rgb_arr);
	free_array(elements);
	free(rgb_arr);
	return (color);
}

bool	check_commas(const char *str)
{
	int	i;
	int	nbrof_commas;

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

unsigned int	get_color(const int *rgb)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	red = rgb[0];
	green = rgb[1];
	blue = rgb[2];
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

mlx_image_t	*get_texture(mlx_t *pMlx, char *path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (texture == NULL)
		fatal(mlx_strerror(mlx_errno));
	image = mlx_texture_to_image(pMlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(image, CUBE_SIZE, CUBE_SIZE);
	return (image);
}
