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

void calculate_delta_offsets(t_ray *ray) {
    double rdx;
    double rdy;
    double ddx;
    double ddy;

    rdx = ray->direction.x;
    rdy = ray->direction.y;

    // Full version
    ddx = sqrt(1 + (rdy * rdy) / (rdx * rdx));
    ddy = sqrt(1 + (rdx * rdx) / (rdy * rdy));

    // middle version
    // ddx = abs(|rayDir| / rayDirX)
    // ddy = abs(|rayDir| / rayDirY)

    // Simplified version
    ray->delta_dist.x = fabs(1 / ray->direction.x);
    ray->delta_dist.y = fabs(1 / ray->direction.y);
}


void calculate_initial_side_distances(t_ray *pRay, t_vector *pPosition, t_point *pMap) {
    if (pRay->direction.x < 0) {
        pRay->step.x = -1;
        pRay->side_distance.x = (pPosition->x - pMap->x) * pRay->delta_dist.x;
    } else {
        pRay->step.x = 1;
        pRay->side_distance.x = (pMap->x + 1.0 - pPosition->x) * pRay->delta_dist.x;
    }
    if (pRay->direction.y < 0) {
        pRay->step.y = -1;
        pRay->side_distance.y = (pPosition->y - pMap->y) * pRay->delta_dist.y;
    } else {
        pRay->step.y = 1;
        pRay->side_distance.y = (pMap->y + 1.0 - pPosition->y) * pRay->delta_dist.y;
    }
}
