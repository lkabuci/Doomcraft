/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:25:37 by relkabou          #+#    #+#             */
/*   Updated: 2023/10/16 18:25:38 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cray.h"

// the floor is used to get the value between 0 and 1
void	set_texture_params(t_seer *pSeer, int xPixel)
{
	double	wall_x;

	if (pSeer->texture.side == HORIZONTAL)
		wall_x = pSeer->player.position.y + pSeer->camera.wall_distance
			* pSeer->camera.direction.y;
	else
		wall_x = pSeer->player.position.x + pSeer->camera.wall_distance
			* pSeer->camera.direction.x;
	wall_x -= floor((wall_x));
	pSeer->texture.tex_x = (int)(wall_x * (double)(CUBE_SIZE));
	if (pSeer->texture.side == HORIZONTAL && pSeer->camera.direction.x > 0)
		pSeer->texture.tex_x = CUBE_SIZE - pSeer->texture.tex_x - 1;
	if (pSeer->texture.side == VERTICAL && pSeer->camera.direction.y < 0)
		pSeer->texture.tex_x = CUBE_SIZE - pSeer->texture.tex_x - 1;
	pSeer->texture.step = CUBE_SIZE / (double)pSeer->vertline.height;
	pSeer->texture.pos = (pSeer->vertline.start - SCREEN_HEIGHT / 2
			+ pSeer->vertline.height / 2) * pSeer->texture.step;
	fill_texture_buffer(pSeer, xPixel, pSeer->vertline.start,
		pSeer->vertline.end);
}

void	set_env(t_seer *pSeer)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT && !pSeer->texture.buffer[j][i])
			pSeer->texture.buffer[j][i] = pSeer->map_info.ceil_color;
	}
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT;
		while (--j >= 0 && !pSeer->texture.buffer[j][i])
			pSeer->texture.buffer[j][i] = pSeer->map_info.floor_color;
	}
}

void	draw_3d_scene(t_seer *pSeer)
{
	int	i;
	int	j;

	i = -1;
	set_env(pSeer);
	while (++i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT)
			mlx_put_pixel(pSeer->image, i, j, pSeer->texture.buffer[j][i]);
	}
	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
			pSeer->texture.buffer[i][j] = 0;
	}
}

void	fill_texture_buffer(t_seer *pSeer, int xPixel, int drawStart, int drawEnd)
{
	int		tex_y;
	int		y;
	t_point	cord;

	y = drawStart - 1;
	while (++y < drawEnd)
	{
		tex_y = (int)pSeer->texture.pos & (CUBE_SIZE - 1);
		pSeer->texture.pos += pSeer->texture.step;
		cord = (t_point){pSeer->texture.tex_x, tex_y};
		if (pSeer->texture.side == HORIZONTAL && pSeer->camera.direction.x > 0)
			pSeer->texture.buffer[y][xPixel] = \
				get_image_color(pSeer->map_info.south_image, cord);
		else if (pSeer->texture.side == HORIZONTAL)
			pSeer->texture.buffer[y][xPixel] = \
				get_image_color (pSeer->map_info.north_image, cord);
		else if (pSeer->camera.direction.y > 0)
			pSeer->texture.buffer[y][xPixel] = \
				get_image_color (pSeer->map_info.east_image, cord);
		else
			pSeer->texture.buffer[y][xPixel] = \
				get_image_color (pSeer->map_info.west_image, cord);
	}
}
