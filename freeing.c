//
// Created by redone on 8/1/23.
//

#include "cray.h"

void    clean_memory(t_seer *pSeer)
{
    // all allocated memory should be freed here
    mlx_delete_image(pSeer->mlx, pSeer->map_info.north_image);
    mlx_delete_image(pSeer->mlx, pSeer->map_info.south_image);
    mlx_delete_image(pSeer->mlx, pSeer->map_info.east_image);
    mlx_delete_image(pSeer->mlx, pSeer->map_info.west_image);
    for (int i = 0; i < pSeer->map_info.map_height; i++)
        free_ptr((void **)&pSeer->map_info.map_2d[i]);
    free_ptr((void **)pSeer->map_info.map_2d);
    free_ptr((void **)&pSeer->map_info);

//    for (int i = 0; i < WIN_HEIGHT; i++)
//        free(pSeer->texture.buffer[i]);
//    free_ptr((void **)pSeer->texture.buffer);

    mlx_close_window(pSeer->mlx);
}



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
    printf("player (%f, %f)\n", pInfo->seer->player.position.x, pInfo->seer->player.position.y);
    printf("%c\n", pInfo->map_2d[(int)pInfo->seer->player.position.y][(int)pInfo->seer->player.position.y]);
}

