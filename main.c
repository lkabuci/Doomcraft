//
// Created by redone on 7/27/23.
//

#include "cray.h"

int main(int argc, const char *argv[])
{
    t_seer seer;

    if (argc != 2)
        fatal("Usage: ./cub3d <map.cub>");
    setup_window(&seer);
    initialize_all_variables(&seer);
    parsing(&seer, argv[1]);
    mlx_loop_hook(seer.mlx, process_movement, &seer);
    mlx_loop_hook(seer.mlx, render, &seer);
    mlx_loop(seer.mlx);
    clean_memory(&seer);
    return 0;
}
