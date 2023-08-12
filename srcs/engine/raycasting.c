//
// Created by redone on 7/30/23.
//

#include "cray.h"

//void setup_camera(t_seer *pSeer, int x);
//t_point get_player_map_position(t_seer *pSeer);
//void ray_casting(t_seer *pSeer);
//
//void render(void *param)
//{
//    t_seer *seer = (t_seer *) param;
//    for (int x = 0; x < WIN_WIDTH; ++x)
//    {
//        setup_camera(seer, x);
//        ray_casting(seer);
//    }
//}
//
//void ray_casting(t_seer *pSeer)
//{
//    v_new(fabs(1 / pSeer->ray.direction.x), fabs(1 / pSeer->ray.direction.y),
//          0);
//    if (pSeer->camera.ray.direction.x < 0)
//    {
//        pRay->step.x = -1;
//        pRay->side_distance.x = (pPosition->x - pMap->x) * pRay->delta_dist.x;
//    }
//    else
//    {
//        pRay->step.x = 1;
//        pRay->side_distance.x =
//                (pMap->x + 1.0 - pPosition->x) * pRay->delta_dist.x;
//    }
//    if (pSeer->camera.ray.direction.y < 0)
//    {
//        pRay->step.y = -1;
//        pRay->side_distance.y = (pPosition->y - pMap->y) * pRay->delta_dist.y;
//    }
//    else
//    {
//        pRay->step.y = 1;
//        pRay->side_distance.y =
//                (pMap->y + 1.0 - pPosition->y) * pRay->delta_dist.y;
//    }
//}
//
//void setup_camera(t_seer *pSeer, int x)
//{
//    double ray_direction_x;
//    double ray_direction_y;
//    ray_direction_x = pSeer->player.direction.x +
//                      pSeer->camera.plane.x * pSeer->camera.camera_x;
//    ray_direction_y = pSeer->player.direction.y +
//                      pSeer->camera.plane.y * pSeer->camera.camera_x;
//    pSeer->ray.direction = v_new(ray_direction_x, ray_direction_y, 0);
//    pSeer->camera.map.x = (int) pSeer->player.position.x;
//    pSeer->camera.map.y = (int) pSeer->player.position.y;
//}
//
//t_point get_player_map_position(t_seer *pSeer)
//{
//    t_point position;
//    position = (t_point) {0, 0};
//    for (int x = 0; x < pSeer->map_info->map_width; ++x)
//    {
//        for (int y = 0; y < pSeer->map_info->map_height; ++y)
//        {
//            if (pSeer->map_info->map_2d[y][x] == '0')
//            {
//                position.x = x;
//                position.y = y;
//                return position;
//            }
//        }
//    }
//    return position;
//}
