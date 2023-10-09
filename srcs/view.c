#include "../includes/cray.h"

void	change_to_left(t_seer *pSeer, double rotSpeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pSeer->player.direction.x;
	pSeer->player.direction.x = pSeer->player.direction.x * cos(rotSpeed)
		- pSeer->player.direction.y * sin(rotSpeed);
	pSeer->player.direction.y = old_dir_x * sin(rotSpeed)
		+ pSeer->player.direction.y * cos(rotSpeed);
	old_plane_x = pSeer->camera.plane.x;
	pSeer->camera.plane.x = pSeer->camera.plane.x * cos(rotSpeed)
		- pSeer->camera.plane.y * sin(rotSpeed);
	pSeer->camera.plane.y = old_plane_x * sin(rotSpeed) + pSeer->camera.plane.y
		* cos(rotSpeed);
}

void	change_to_right(t_seer *pSeer, double rotSpeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pSeer->player.direction.x;
	pSeer->player.direction.x = pSeer->player.direction.x * cos(-rotSpeed)
		- pSeer->player.direction.y * sin(-rotSpeed);
	pSeer->player.direction.y = old_dir_x * sin(-rotSpeed)
		+ pSeer->player.direction.y * cos(-rotSpeed);
	old_plane_x = pSeer->camera.plane.x;
	pSeer->camera.plane.x = pSeer->camera.plane.x * cos(-rotSpeed)
		- pSeer->camera.plane.y * sin(-rotSpeed);
	pSeer->camera.plane.y = old_plane_x * sin(-rotSpeed) + pSeer->camera.plane.y
		* cos(-rotSpeed);
}

void	mouse_move(t_seer *pSeer)
{
	double	half_screen;

	half_screen = pSeer->image->width / 2.0;
	mlx_get_mouse_pos(pSeer->mlx, &pSeer->mouse.x, &pSeer->mouse.y);
	if (pSeer->mouse.x < half_screen)
		change_to_left(pSeer, ROTATE_SPEED);
	else if (pSeer->mouse.x > half_screen)
		change_to_right(pSeer, ROTATE_SPEED);
	mlx_set_mouse_pos(pSeer->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
