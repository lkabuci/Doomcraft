/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:25:39 by relkabou          #+#    #+#             */
/*   Updated: 2023/10/16 18:25:40 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cray.h"

unsigned int	get_image_color(mlx_image_t *image, t_point p)
{
	unsigned int	color;
	unsigned int	index;

	index = ((p.y % image->height) * image->width + (p.x % image->width))
		* sizeof(unsigned int);
	color = image->pixels[index] << 24;
	color |= image->pixels[index + 1] << 16;
	color |= image->pixels[index + 2] << 8;
	color |= 0x000000FF;
	return (color);
}
