//
// Created by redone on 8/12/23.
//

#include "cray.h"

void setup_window(t_seer *seer)
{
    mlx_set_setting(MLX_STRETCH_IMAGE, false);
    mlx_set_setting(MLX_DECORATED, false);
    seer->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cRay", false);
    if (seer->mlx == NULL)
        fatal(mlx_strerror(mlx_errno));
    seer->image = mlx_new_image(seer->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (seer->image == NULL)
        fatal(mlx_strerror(mlx_errno));
    mlx_image_to_window(seer->mlx, seer->image, 0, 0);
    mlx_set_cursor_mode(seer->mlx, MLX_MOUSE_HIDDEN);
    mlx_set_window_limit(seer->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_WIDTH, WIN_HEIGHT);
}

void initialize_all_variables(t_seer *pSeer)
{
    pSeer->player.seer = pSeer;
    pSeer->map_info.seer = pSeer;
    pSeer->map_info.east_image = NULL;
    pSeer->map_info.west_image = NULL;
    pSeer->map_info.north_image = NULL;
    pSeer->map_info.south_image = NULL;
    pSeer->map_info.map_width = -1;
    pSeer->map_info.ceil_color = -1;
    pSeer->map_info.map_height = 1;
    pSeer->map_info.floor_color = -1;
    pSeer->map_info.map_2d = NULL;
    pSeer->map_info.ptr_saver = NULL;
}