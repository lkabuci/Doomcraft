#include "../includes/cray.h"

void	position_direction(t_seer *pSeer, t_camera *pCamera, int xPixel)
{
	pSeer->dda.iter = 2 * xPixel / (double)SCREEN_WIDTH - 1;
	pCamera->direction.x = pSeer->player.direction.x + pSeer->camera.plane.x
		* pSeer->dda.iter;
	pCamera->direction.y = pSeer->player.direction.y + pSeer->camera.plane.y
		* pSeer->dda.iter;
	pCamera->map_x = (int)pSeer->player.position.x;
	pCamera->map_y = (int)pSeer->player.position.y;
	pSeer->dda.delta_distance.y = fabs(1 / pCamera->direction.y);
	pSeer->dda.delta_distance.x = fabs(1 / pCamera->direction.x);
}

void	calculate_offsets(t_seer *pSeer, t_camera *pCamera)
{
	if (pCamera->direction.x < 0)
	{
		pSeer->dda.step_x = -1;
		pSeer->dda.side_distance.x = (pSeer->player.position.x - pCamera->map_x)
			* pSeer->dda.delta_distance.x;
	}
	else
	{
		pSeer->dda.step_x = 1;
		pSeer->dda.side_distance.x = (pCamera->map_x + 1.0
				- pSeer->player.position.x) * pSeer->dda.delta_distance.x;
	}
	if (pCamera->direction.y < 0)
	{
		pSeer->dda.step_y = -1;
		pSeer->dda.side_distance.y = (pSeer->player.position.y - pCamera->map_y)
			* pSeer->dda.delta_distance.y;
	}
	else
	{
		pSeer->dda.step_y = 1;
		pSeer->dda.side_distance.y = (pCamera->map_y + 1.0
				- pSeer->player.position.y) * pSeer->dda.delta_distance.y;
	}
}

void	dda(t_seer *pSeer, t_camera *pCamera, int *side)
{
	while (true)
	{
		if (pSeer->dda.side_distance.x < pSeer->dda.side_distance.y)
		{
			pSeer->dda.side_distance.x += pSeer->dda.delta_distance.x;
			pCamera->map_x += pSeer->dda.step_x;
			*side = 0;
		}
		else
		{
			pSeer->dda.side_distance.y += pSeer->dda.delta_distance.y;
			pCamera->map_y += pSeer->dda.step_y;
			*side = 1;
		}
		if (pSeer->map_info.map_2d[pCamera->map_x][pCamera->map_y] == '1')
			break ;
	}
}

void	vertline(t_seer *pSeer, t_camera *pCamera, int side)
{
	pCamera->wall_distance = (pSeer->dda.side_distance.y
			- pSeer->dda.delta_distance.y);
	if (side == 0)
		pCamera->wall_distance = (pSeer->dda.side_distance.x
				- pSeer->dda.delta_distance.x);
	pSeer->vertline.height = (int)(SCREEN_HEIGHT / pCamera->wall_distance);
	pSeer->vertline.start = -pSeer->vertline.height / 2 + SCREEN_HEIGHT / 2;
	if (pSeer->vertline.start < 0)
		pSeer->vertline.start = 0;
	pSeer->vertline.end = pSeer->vertline.height / 2 + SCREEN_HEIGHT / 2;
	if (pSeer->vertline.end >= SCREEN_HEIGHT)
		pSeer->vertline.end = SCREEN_HEIGHT - 1;
}
