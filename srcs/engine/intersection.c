//
// Created by redone on 8/4/23.
//

#include "cray.h"

/*
 * scale factor = 1 / ray direction
 * scale X = ray direction X * scale factor = 1
 * scale Y = ray direction Y * scale factor = ray direction Y / ray direction X
 * delta distance x = sqrt(1 + (ray direction Y / ray direction X) ^ 2)
 * same goes for delta distance y
 * delta distance y = sqrt(1 + (ray direction X / ray direction Y) ^ 2)
 */

void calculate_delta_offsets(t_ray *ray)
{
    ray->delta_dist = v_new(fabs(1 / ray->direction.x),
                            fabs(1 / ray->direction.y));
}

void calculate_initial_side_distances(t_ray *pRay, t_vector *pPosition,
                                      t_point *pMap)
{
    if (pRay->direction.x < 0)
    {
        pRay->step.x = -1;
        pRay->side_distance.x = (pPosition->x - pMap->x) * pRay->delta_dist.x;
    }
    else
    {
        pRay->step.x = 1;
        pRay->side_distance.x =
                (pMap->x + 1.0 - pPosition->x) * pRay->delta_dist.x;
    }
    if (pRay->direction.y < 0)
    {
        pRay->step.y = -1;
        pRay->side_distance.y = (pPosition->y - pMap->y) * pRay->delta_dist.y;
    }
    else
    {
        pRay->step.y = 1;
        pRay->side_distance.y =
                (pMap->y + 1.0 - pPosition->y) * pRay->delta_dist.y;
    }
}

void hit_wall(t_seer *pSeer, int *side)
{
    while (true)
    {
        if (pSeer->ray.side_distance.x < pSeer->ray.side_distance.y)
        {
            pSeer->ray.side_distance.x += pSeer->ray.delta_dist.x;
            pSeer->camera.map.x += pSeer->ray.step.x;
            // texture side
            *side = 0;
        } else
        {
            pSeer->ray.side_distance.y += pSeer->ray.delta_dist.y;
            pSeer->camera.map.y += pSeer->ray.step.y;
            // texture side
            *side = 1;
        }
        if (pSeer->map_info.map_2d[pSeer->camera.map.x][pSeer->camera.map.y] ==
            '1')
            break;
    }
}

void calculate_wall_height(t_seer *pSeer, int side)
{
    pSeer->ray.perp_wall_dist = (pSeer->ray.side_distance.y -
                                 pSeer->ray.delta_dist.y);
    if (side == 0)
        pSeer->ray.perp_wall_dist = (pSeer->ray.side_distance.x -
                                     pSeer->ray.delta_dist.x);
    pSeer->line.line_height = (int) (WIN_HEIGHT / pSeer->ray.perp_wall_dist);
    pSeer->line.draw_start = -pSeer->line.line_height / 2 + WIN_HEIGHT / 2;
    if (pSeer->line.draw_start < 0)
        pSeer->line.draw_start = 0;
    pSeer->line.draw_end = pSeer->line.line_height / 2 + WIN_HEIGHT / 2;
    if (pSeer->line.draw_end >= WIN_HEIGHT)
        pSeer->line.draw_end = WIN_HEIGHT - 1;
}
