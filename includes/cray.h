//
// Created by redone on 7/27/23.
//

#ifndef MARIO3D_MARIO_H
#define MARIO3D_MARIO_H

#include "libft.h"
#include "MLX42.h"
#include "vector.h"

# define NBR_OF_ELEMENTS 6
# define SPACES " \t\n"
# define CUBE_SIZE 64
# define WIN_WIDTH 1024
# define WIN_HEIGHT 512

typedef struct s_seer t_seer;
typedef struct s_player t_player;
typedef struct s_map_info t_map_info;
typedef struct s_texture t_texture;

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

struct s_texture {
    unsigned int **buffer;
    // TODO: add extra textures variables
};

struct s_player {
    char first_view;
    int x_pos;
    int y_pos;
};

struct s_seer {
    mlx_t *mlx;
    mlx_image_t *image;
    t_map_info *map_info;
    t_player player;
    t_texture texture;
};

// parsing/parsing.c
void parsing(t_seer *seer, const char *map_filename);

// parsing/utils.c
char *readline(int fd);
void check_filename(const char *filename);

bool is_all_num(char **elements);

int ft_split_len(char **elements);

void skip_till_first_map_line(t_map_info *pInfo);

// parsing/map_parsing.c
void check_map(t_map_info *pInfo, char **pString);
void process_movement(void *params);

// Utils.c
void fatal(const char *msg);


// Freeing
void    clean_memory(t_seer *pSeer);
void print_map_data(t_map_info *pInfo);
void initialize_all_variables(t_seer *pSeer);

// rendering
void    render(void *param);

// shapes
void	draw_line(mlx_image_t *image, t_vector p0, t_vector p1, unsigned int color);
void	draw_circle(mlx_image_t *image, t_vector p, int size, uint32_t color);
void	draw_square(mlx_image_t *image, t_vector p, int size, uint32_t color);

#endif //MARIO3D_MARIO_H
