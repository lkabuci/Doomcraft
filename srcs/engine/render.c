//
// Created by redone on 8/2/23.
//

#include "cray.h"

void draw_player(t_seer *pSeer);

void draw_floor_and_ceiling(t_seer *pSeer);

void render(void *param) {
    t_seer *seer = (t_seer *) param;
//    draw_floor_and_ceiling(seer);

    for (int x = 0; x < WIN_WIDTH; x++) {
        // Phase 1: Calculate ray position and direction
        seer->camera.camera_x = 2 * (x / (double) WIN_WIDTH) - 1;
        seer->ray.direction.x = seer->player.direction.x + seer->camera.plane.x * seer->camera.camera_x;
        seer->ray.direction.y = seer->player.direction.y + seer->camera.plane.y * seer->camera.camera_x;
        seer->camera.map.x = (int) seer->player.position.x;
        seer->camera.map.y = (int) seer->player.position.y;
        seer->ray.delta_dist.x = fabs(1 / seer->ray.direction.x);
        seer->ray.delta_dist.y = fabs(1 / seer->ray.direction.y);

        // Phase 2: Calculate step and initial sideDist
    }

    draw_player(seer);
}

void draw_floor_and_ceiling(t_seer *pSeer) {
    for (int y = 0; y < WIN_HEIGHT; y++) {
        for (int x = 0; x < WIN_WIDTH; x++) {
            if (y < WIN_HEIGHT / 2)
                mlx_put_pixel(pSeer->image, x, y, pSeer->map_info->ceil_color);
            else
                mlx_put_pixel(pSeer->image, x, y, pSeer->map_info->floor_color);
        }
    }
}

void draw_player(t_seer *pSeer) {
    (void) pSeer;
}
