//
// Created by redone on 7/27/23.
//

#include "cray.h"

void initialize_all_variables(t_seer *pSeer);
void    clean_memory(t_seer *pSeer);
void setup_window(t_seer *seer);

void print_map_data(t_map_info *pInfo)
{
    printf("map_width: %d\n", pInfo->map_width);
    printf("map_height: %d\n", pInfo->map_height);
    printf("ceil_color: %ld\n", pInfo->ceil_color);
    printf("floor_color: %ld\n", pInfo->floor_color);
    printf("north_image: %p\n", pInfo->north_image);
    printf("south_image: %p\n", pInfo->south_image);
    printf("east_image: %p\n", pInfo->east_image);
    printf("west_image: %p\n", pInfo->west_image);
    printf("map_2d:\n");
    for (int i = 0; i < pInfo->map_height; i++)
        printf("%s\n", pInfo->map_2d[i]);
    printf("player (%i, %i)\n", pInfo->seer->player->x_pos, pInfo->seer->player->y_pos);
    printf("%c\n", pInfo->map_2d[pInfo->seer->player->x_pos][pInfo->seer->player->y_pos]);
}

int main (int argc, const char *argv[])
{
    t_seer seer;

    if (argc != 2)
        fatal("Invalid number of arguments.");
    setup_window(&seer);
    initialize_all_variables(&seer);
    parsing(&seer, argv[1]);
    print_map_data(seer.map_info);
    mlx_loop_hook(seer.mlx, process_mouvement, &seer);
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
    mlx_set_cursor_mode(seer->mlx, MLX_MOUSE_HIDDEN);
    mlx_set_window_limit(seer->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_WIDTH, WIN_HEIGHT);
}

void initialize_all_variables(t_seer *pSeer) {
    pSeer->map_info = ft_calloc(sizeof(t_map_info));
    pSeer->player = ft_calloc(sizeof(t_player));
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
