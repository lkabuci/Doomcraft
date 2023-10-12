//
// Created by redone on 7/27/23.
//

#include "includes/cray.h"

int	main(int argc, const char *argv[])
{
	t_seer	var;

	if (argc != 2)
		fatal(USAGE);
	init_window(&var);
	parsing(&var, argv[1]);
	init(&var);
	mlx_loop_hook(var.mlx, move_hook, &var);
	mlx_loop_hook(var.mlx, draw_hook, &var);
	mlx_loop(var.mlx);
	mlx_terminate(var.mlx);
	return (EXIT_SUCCESS);
}

void	end_game(t_seer *pSeer)
{
	int	i;

	i = -1;
	free_array(pSeer->map_info.map_2d);
	mlx_delete_image(pSeer->mlx, pSeer->image);
	mlx_close_window(pSeer->mlx);
	while (++i < SCREEN_HEIGHT)
		free(pSeer->texture.buffer[i]);
	free(pSeer->texture.buffer);
	exit(0);
}
