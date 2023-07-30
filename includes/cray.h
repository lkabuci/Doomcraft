//
// Created by redone on 7/27/23.
//

#ifndef MARIO3D_MARIO_H
#define MARIO3D_MARIO_H

#include "libft.h"
#include "MLX42.h"

# define NBR_OF_ELEMENTS 6
# define SPACES " \t\n"
# define CUBE_SIZE 64
# define WIN_WIDTH 1024
# define WIN_HEIGHT 512

typedef struct s_seer t_seer;
typedef struct s_player t_player;
typedef struct s_map_info t_map_info;

struct s_seer {
    mlx_t *mlx;
    mlx_image_t *image;
    t_map_info *map_info;
    t_player *player;
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
    int fd;
    t_seer *seer;
};

struct s_player {
    char first_view;
    int x_pos;
    int y_pos;
};

// parsing/parsing.c
void parsing(t_seer *seer, const char *map_filename);

// parsing/utils.c
char *readline(int fd);

bool is_all_num(char **elements);

int ft_split_len(char **elements);

void skip_till_first_map_line(t_map_info *pInfo);

// parsing/map_parsing.c
void check_map(t_map_info *pInfo, char **pString);
void process_mouvement(void *params);

// Utils.c
void fatal(const char *msg);

#endif //MARIO3D_MARIO_H
