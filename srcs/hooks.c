#include "../includes/cray.h"

void move_hook(void *param)
{
	t_seer *seer;

	seer = param;
	if (mlx_is_key_down(seer->mlx, MLX_KEY_ESCAPE))
		end_game(seer);
	if (mlx_is_key_down(seer->mlx, MLX_KEY_W))
		move_forward(seer, MOVE_SPEED);
	if (mlx_is_key_down(seer->mlx, MLX_KEY_S))
		move_backward(seer, MOVE_SPEED);
	if (mlx_is_key_down(seer->mlx, MLX_KEY_A))
		move_left(seer, MOVE_SPEED);
	if (mlx_is_key_down(seer->mlx, MLX_KEY_D))
		move_right(seer, MOVE_SPEED);
	if (mlx_is_key_down(seer->mlx, MLX_KEY_LEFT))
		change_to_left(seer, ROTATE_SPEED);
	if (mlx_is_key_down(seer->mlx, MLX_KEY_RIGHT))
		change_to_right(seer, ROTATE_SPEED);
	mouse_move(seer);
}

void draw_hook(void *args)
{
	t_seer *seer;
	int x;

	seer = args;
	ft_memset(seer->image->pixels, 0, seer->image->width * seer->image->height
			* sizeof(uint32_t));
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		position_direction(seer, &seer->camera, x);
		calculate_offsets(seer, &seer->camera);
		dda(seer, &seer->camera, &seer->texture.side);
		vertline(seer, &seer->camera, seer->texture.side);
		set_texture_params(seer, x);
	}
	draw_3d_scene(seer);
}
