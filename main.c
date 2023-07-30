//
// Created by redone on 7/27/23.
//

#include "cray.h"

void initialize_all_variables(t_seer *pSeer);
void    clean_memory(t_seer *pSeer);
void setup_window(t_seer *seer);

int main (int argc, const char *argv[])
{
    t_seer seer;

    if (argc != 2)
        fatal("Invalid number of arguments.");
    setup_window(&seer);
    initialize_all_variables(&seer);
    parsing(&seer, argv[1]);
    for (int i = 0; i < seer.map_info->map_height; i++)
        printf("%s\n", seer.map_info->map_2d[i]);
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
    mlx_set_cursor_mode(seer->mlx, MLX_MOUSE_HIDDEN);
    mlx_set_window_limit(seer->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_WIDTH, WIN_HEIGHT);
}

void initialize_all_variables(t_seer *pSeer) {
    pSeer->map_info = ft_calloc(sizeof(t_map_info));
    pSeer->map_info->seer = pSeer;
    pSeer->map_info->east_image = NULL;
    pSeer->map_info->west_image = NULL;
    pSeer->map_info->north_image = NULL;
    pSeer->map_info->south_image = NULL;
    pSeer->map_info->map_width = -1;
    pSeer->map_info->ceil_color = -1;
    pSeer->map_info->map_height = 1;
    pSeer->map_info->floor_color = -1;
    pSeer->map_info->map_2d = NULL;
    pSeer->map_info->ptr_saver = NULL;
}

void    clean_memory(t_seer *pSeer)
{
    // all allocated memory should be freed here
    free_ptr((void **)&pSeer->map_info);
    mlx_delete_image(pSeer->mlx, pSeer->map_info->north_image);
    mlx_delete_image(pSeer->mlx, pSeer->map_info->south_image);
    mlx_delete_image(pSeer->mlx, pSeer->map_info->east_image);
    mlx_delete_image(pSeer->mlx, pSeer->map_info->west_image);
    mlx_close_window(pSeer->mlx);
}
