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
