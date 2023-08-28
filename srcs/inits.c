#include "../includes/cray.h"

void initialize_all_variables(t_seer *pSeer);

void	init_window(t_seer *pSeer)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	mlx_set_setting(MLX_DECORATED, false);
    pSeer->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "WolFeinstein 3D", true);
	if (pSeer->mlx == NULL)
	{
		fatal(mlx_strerror(mlx_errno));
	}
	mlx_set_cursor_mode(pSeer->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_window_limit(pSeer->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH,
                         SCREEN_HEIGHT);
    initialize_all_variables(pSeer);
}

void initialize_all_variables(t_seer *pSeer) {
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

void	init(t_seer *pSeer)
{
	int	i;

	i = -1;
    pSeer->map_info.map_2d[(int)pSeer->player.position.x][(int)pSeer->player.position.y] = 'P';
    pSeer->image = mlx_new_image(pSeer->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_image_to_window(pSeer->mlx, pSeer->image, 0, 0);
    pSeer->texture.buffer = ft_calloc((SCREEN_HEIGHT) * sizeof(uint32_t *));
	while (++i < SCREEN_HEIGHT)
        pSeer->texture.buffer[i] = ft_calloc(sizeof(uint32_t) * (SCREEN_WIDTH));
}
