//
// Created by redone on 8/2/23.
//

#include "cray.h"

void draw_player(t_seer *pSeer);

void draw_floor_and_ceiling(t_seer *pSeer);


void setup_camera(t_seer *pSeer, int x);

void render(void *param) {
    t_seer *seer = (t_seer *) param;
//    draw_floor_and_ceiling(seer);

    for (int x = 0; x < WIN_WIDTH; x++) {
        // Phase 1: Calculate ray position and direction
        setup_camera(seer, x);

        // Phase 2: Calculate delta offsets and side distances
        calculate_delta_offsets(&seer->ray);
        calculate_initial_side_distances(&seer->ray, &seer->player.position, &seer->camera.map);

        // Phase 3: DDA
        hit_wall(seer, &seer->texture.side);

        // Phase 4: Calculate wall height
        calculate_wall_height(seer, seer->texture.side);

    }

    draw_player(seer);
}

void setup_camera(t_seer *pSeer, int x) {
    pSeer->camera.camera_x = 2 * (x / (double) WIN_WIDTH) - 1;
    pSeer->ray.direction.x = pSeer->player.direction.x + pSeer->camera.plane.x * pSeer->camera.camera_x;
    pSeer->ray.direction.y = pSeer->player.direction.y + pSeer->camera.plane.y * pSeer->camera.camera_x;
    pSeer->camera.map.x = (int) pSeer->player.position.x;
    pSeer->camera.map.y = (int) pSeer->player.position.y;
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
}
