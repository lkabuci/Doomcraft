#ifndef CRAY_H
# define CRAY_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include <math.h>

// WINDOW
# define CUBE_SIZE 64
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 512

// GAME
# define MOVE_SPEED 0.08f
# define ROTATE_SPEED 0.04f

// MISC
# define SPACES " \t\n"
# define NBROF_ELEMENTS 6

/* ERRORS_MACRO */
# define ERR_RGB "invalid rgb"
# define ERR_MAP_INFO "Invalid map_info !!"
# define ERR_ELEMENT "Invalid map_info elements"
# define ERR_OPEN "Can't open the file"
# define ERR_DUPLICATED "duplicated or invalid element"
# define ERR_INFO "elements after map_info"
# define ERR_WHOLES "Map contains wholes"
# define ERR_N_PLAYER "Map doesn't contain player"
# define ERR_M_PLAYER "Map contains more than one player"
# define ERR_MALLOC "Memory allocation failed"
# define ERR_INVALID_CHAR	"Map contains invalid characters"
# define ERR_EXTENSION	"Invalid file extension"
# define ERR_NO_WALLS	"Map is not surrounded by walls"
# define USAGE	"Usage: ./cub3D <map_2d.cub>"


typedef struct s_player		t_player;
typedef struct s_vector		t_vector;
typedef struct s_point		t_point;
typedef struct s_seer		t_seer;
typedef struct s_map_info	t_map_info;
typedef struct s_camera		t_camera;
typedef struct s_line		t_line;
typedef struct s_texture	t_texture;
typedef struct s_dda		t_dda;

struct						s_point
{
	int						x;
	int						y;
};

struct						s_vector
{
	double					x;
	double					y;
};

struct						s_line
{
	int						height;
	int						start;
	int						end;
};

struct						s_player
{
	char					first_view;
	t_vector				position;
	t_vector				direction;
	t_seer					*seer;
};

struct						s_texture
{
	unsigned int			**buffer;
	double					pos;
	int						tex_x;
	int						side;
	double					step;
};

struct						s_map_info
{
	mlx_image_t				*north_image;
	mlx_image_t				*south_image;
	mlx_image_t				*west_image;
	mlx_image_t				*east_image;
	long					floor_color;
	long					ceil_color;
	int						map_height;
	int						map_width;
	char					**map_2d;
	char					*ptr_saver;
	int						fd;
	t_seer					*seer;
};

struct						s_dda
{
	double					iter;
	t_vector				side_distance;
	t_vector				delta_distance;
	int						step_x;
	int						step_y;
};

struct						s_camera
{
	t_vector				plane;
	int						map_x;
	int						map_y;
	t_vector				direction;
	double					wall_distance;
};

struct						s_seer
{
	t_dda					dda;
	t_map_info				map_info;
	mlx_t					*mlx;
	t_line					vertline;
	t_point					mouse;
	t_camera				camera;
	mlx_image_t				*image;
	t_player				player;
	t_texture				texture;
	bool					is_mouse_active;
};

void						fill_map(t_map_info *pInfo);
unsigned int				get_color(const int *rgb);
bool						check_commas(const char *str);
mlx_image_t					*get_texture(mlx_t *pMlx, char *path);
long						get_rgb(char *value);
void						fill_elements(mlx_t *mlx, t_map_info *pInfo, char *key, char *value);
void						parsing(t_seer *seer, const char *filename);
void						check_filename(const char *filename);
void						check_map(t_map_info *pInfo, char **pString);
char						*readline(int fd);
bool						is_all_num(char **elements);
void						skip_till_first_map_line(t_map_info *pInfo);

void						move_hook(void *param);
void						draw_hook(void *args);
void						init_window(t_seer *pSeer);
void						change_to_left(t_seer *pSeer, double rotSpeed);
void						change_to_right(t_seer *pSeer, double rotSpeed);
void						move_forward(t_seer *pSeer, double moveSpeed);
void						move_backward(t_seer *pSeer, double moveSpeed);
void						move_left(t_seer *pSeer, double moveSpeed);
void						move_right(t_seer *pSeer, double moveSpeed);
void						free_array(char **split);
void						end_game(t_seer *pSeer);
void						mouse_move(t_seer *pSeer);
void						init(t_seer *pSeer);
void						position_direction(t_seer *pSeer, t_camera *pCamera,
								int xPixel);
void						calculate_offsets(t_seer *pSeer, t_camera *pCamera);
void						dda(t_seer *pSeer, t_camera *pCamera, int *side);
void						vertline(t_seer *pSeer, t_camera *pCamera,
								int side);
unsigned int				get_image_color(mlx_image_t *image, t_point p);
void						set_texture_params(t_seer *pSeer, int xPixel);
void						set_env(t_seer *pSeer);
void						draw_3d_scene(t_seer *pSeer);
void						fill_texture_buffer(t_seer *pSeer, int x,
								int drawStart, int drawEnd);
#endif // !CRAY_H
