//
// Created by redone on 7/27/23.
//

#ifndef MARIO3D_MARIO_H
#define MARIO3D_MARIO_H

#include "libft.h"
#include "MLX42.h"

typedef struct s_seer t_seer;
typedef struct s_map_info t_map_info;
typedef struct s_vect t_vect;

struct s_seer {
    t_map_info *map_info;
};

struct s_map_info {
    mlx_image_t *north_image;
    mlx_image_t *east_image;
    mlx_image_t *west_image;
    mlx_image_t *south_image;
    long floor_color;
    long ceil_color;
    int map_height;
    int map_width;
    char **map_2d;
    char *ptr_saver;
};

// parsing/parsing.c
void    parsing(t_seer *seer, char *map_filename);

// Utils.c
void    fatal(char *msg);

#endif //MARIO3D_MARIO_H
