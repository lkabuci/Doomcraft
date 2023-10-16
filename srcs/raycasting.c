/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:25:34 by relkabou          #+#    #+#             */
/*   Updated: 2023/10/16 18:35:25 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pSeer->dda.scaling_factor.x = sqrt(1 + (pCamera->direction.y * \
		pCamera->direction.y) / (pCamera->direction.x * pCamera->direction.x));
	pSeer->dda.scaling_factor.y = sqrt(1 + (pCamera->direction.x * \
		pCamera->direction.x) / (pCamera->direction.y * pCamera->direction.y));
}

/*
	adding 1.0 to the player position
	is to avoid the case where the player is on the grid.
*/
void	calculate_initial_distance(t_seer *pSeer, t_camera *pCamera)
{
	if (pCamera->direction.x < 0)
	{
		pSeer->dda.step_x = -1;
		pSeer->dda.distance.x = (pSeer->player.position.x - pCamera->map_x)
			* pSeer->dda.scaling_factor.x;
	}
	else
	{
		pSeer->dda.step_x = 1;
		pSeer->dda.distance.x = (pCamera->map_x + 1.0
				- pSeer->player.position.x) * pSeer->dda.scaling_factor.x;
	}
	if (pCamera->direction.y < 0)
	{
		pSeer->dda.step_y = -1;
		pSeer->dda.distance.y = (pSeer->player.position.y - pCamera->map_y)
			* pSeer->dda.scaling_factor.y;
	}
	else
	{
		pSeer->dda.step_y = 1;
		pSeer->dda.distance.y = (pCamera->map_y + 1.0
				- pSeer->player.position.y) * pSeer->dda.scaling_factor.y;
	}
}

void	dda_loop(t_seer *pSeer, t_camera *pCamera, int *side)
{
	while (true)
	{
		if (pSeer->dda.distance.x < pSeer->dda.distance.y)
		{
			pSeer->dda.distance.x += pSeer->dda.scaling_factor.x;
			pCamera->map_x += pSeer->dda.step_x;
			*side = HORIZONTAL;
		}
		else
		{
			pSeer->dda.distance.y += pSeer->dda.scaling_factor.y;
			pCamera->map_y += pSeer->dda.step_y;
			*side = VERTICAL;
		}
		if (pSeer->map_info.map_2d[pCamera->map_x][pCamera->map_y] == '1')
			break ;
	}
}

/*
	* ( 1 - step_x ) / 2 = 1 : if step_x = -1 and 0 : if step_x = 1
		why?	because if step_x = -1, then the player is on the right 
				side of the wall,
				1 is already added in the calculation of the initial distance.
	* mapX - playerX + (1 - stepX) / 2 is the number of square the player has
				to crossed in the X axis.
	pCamera.direction is the ray direction vector so we can get the
		perpendicular wall distance.
*/

void	vertline(t_seer *pSeer, t_camera *pCamera, int side)
{
	if (side == HORIZONTAL)
		pCamera->wall_distance = fabs((pCamera->map_x - \
			pSeer->player.position.x + (1 - pSeer->dda.step_x) / 2) \
			/pCamera->direction.x);
	else
		pCamera->wall_distance = fabs((pCamera->map_y - \
		pSeer->player.position.y + (1 - pSeer->dda.step_y) / 2) \
		/ pCamera->direction.y);
	if (pCamera->wall_distance == 0)
		pCamera->wall_distance = 0.0001;
	pSeer->vertline.height = fabs(SCREEN_HEIGHT / pCamera->wall_distance);
	pSeer->vertline.start = -pSeer->vertline.height / 2 + SCREEN_HEIGHT / 2;
	if (pSeer->vertline.start < 0)
		pSeer->vertline.start = 0;
	pSeer->vertline.end = pSeer->vertline.height / 2 + SCREEN_HEIGHT / 2;
	if (pSeer->vertline.end >= SCREEN_HEIGHT)
		pSeer->vertline.end = SCREEN_HEIGHT - 1;
}
