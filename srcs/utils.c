#include "../includes/cray.h"

uint32_t get_image_color(mlx_image_t *image, t_point p)
{
	uint32_t color;
	uint32_t index;

	index = (p.y % image->height * image->width + p.x % image->width) * 4;
	color = image->pixels[index] << 24;
	color |= image->pixels[index + 1] << 16;
	color |= image->pixels[index + 2] << 8;
	color |= 0x000000FF;
	return (color);
}
