//
// Created by redone on 8/2/23.
//

#include "cray.h"

static void	init_line_values(t_vector *inc, t_vector p0, t_vector p1, t_vector *delta);

void	draw_line(mlx_image_t *image, t_vector p0, t_vector p1, unsigned int color)
{
	int			err;
	int			e2;
	t_vector      increment_step;
	t_vector      delta;

    init_line_values(&increment_step, p0, p1, &delta);
	err = (int)delta.x + (int)delta.y;
	while (true)
	{
		mlx_put_pixel(image, (int)p0.x, (int)p0.y, color);
		if ((int)p0.x == (int)p1.x && (int)p0.y == (int)p1.y)
			break ;
		e2 = 2 * err;
		if (e2 >= (int)delta.y)
		{
			err += (int)delta.y;
			p0.x += (int)increment_step.x;
		}
		if (e2 <= (int)delta.x)
		{
			err += (int)delta.x;
			p0.y += (int)increment_step.y;
		}
	}
}

void	draw_circle(mlx_image_t *image, t_vector p, int size, uint32_t color)
{
	int			i;
	int			j;
	int			radius;
	t_vector	    c;
	t_vector	    d;

	i = (int)p.x - 1;
	radius = size / 2;
	c.x = (int)p.x + radius;
	c.y = (int)p.y + radius;
	while (++i < (int)p.x + size)
	{
		j = (int)p.y - 1;
		while (++j < (int)p.y + size)
		{
			d.x = i - (int)c.x;
			d.y = j - (int)c.y;
			if ((int)d.x * (int)d.x + (int)d.y * (int)d.y <= radius * radius)
				mlx_put_pixel(image, i, j, color);
		}
	}
}

void	draw_square(mlx_image_t *image, t_vector p, int size, uint32_t color)
{
	int	x_end;
	int	y_end;
	int	j;

	x_end = (int)p.x + size;
	y_end = (int)p.y + size;
	j = (int)p.y;
	while ((int)p.x < x_end)
	{
		p.y = j;
		while ((int)p.y < y_end)
		{
			mlx_put_pixel(image, (int)p.x, (int)p.y, color);
			p.y++;
		}
		p.x++;
	}
}

static void	init_line_values(t_vector *inc, t_vector p0, t_vector p1, t_vector *delta)
{
	delta->x = +abs((int)p1.x - (int)p0.x);
	delta->y = -abs((int)p1.y - (int)p0.y);
	inc->x = 1;
	inc->y = 1;
	if (p1.x < p0.x)
		inc->x = -1;
	if (p1.y < p0.y)
		inc->y = -1;
}
