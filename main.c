//
// Created by redone on 7/27/23.
//

#include "cray.h"

void setup_window(t_seer *seer);

int main (int argc, const char *argv[])
{
    t_seer seer;

    if (argc != 2)
        fatal("Invalid number of arguments.");
    setup_window(&seer);
    initialize_all_variables(&seer);
    parsing(&seer, argv[1]);
    mlx_loop_hook(seer.mlx, process_movement, &seer);
    mlx_loop_hook(seer.mlx, render, &seer);
    mlx_loop(seer.mlx);
    clean_memory(&seer);
    return 0;
}

void setup_window(t_seer *seer)
{
    mlx_set_setting(MLX_STRETCH_IMAGE, false);
    mlx_set_setting(MLX_DECORATED, false);
    seer->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", false);
    if (seer->mlx == NULL)
        fatal(mlx_strerror(mlx_errno));
    seer->image = mlx_new_image(seer->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (seer->image == NULL)
        fatal(mlx_strerror(mlx_errno));
    mlx_image_to_window(seer->mlx, seer->image, 0, 0);
    mlx_set_cursor_mode(seer->mlx, MLX_MOUSE_HIDDEN);
    mlx_set_window_limit(seer->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_WIDTH, WIN_HEIGHT);
}
