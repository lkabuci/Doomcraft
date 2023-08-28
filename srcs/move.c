#include "../includes/cray.h"

static bool	can_move(char block);

void	move_forward(t_seer *pSeer, double moveSpeed)
{
	if (can_move(pSeer->map_info.map_2d[(int)(pSeer->player.position.x + pSeer->player.direction.x
                                                                         * moveSpeed)][(int)(pSeer->player.position.y)]))
        pSeer->player.position.x += pSeer->player.direction.x * moveSpeed;
	if (can_move(pSeer->map_info.map_2d[(int)(pSeer->player.position.x)][(int)(pSeer->player.position.y + pSeer->player.direction.y
                                                                                                          * moveSpeed)]))
        pSeer->player.position.y += pSeer->player.direction.y * moveSpeed;
}

void	move_backward(t_seer *pSeer, double moveSpeed)
{
	if (can_move(pSeer->map_info.map_2d[(int)(pSeer->player.position.x - pSeer->player.direction.x
                                                                         * moveSpeed)][(int)(pSeer->player.position.y)]))
        pSeer->player.position.x -= pSeer->player.direction.x * moveSpeed;
	if (can_move(pSeer->map_info.map_2d[(int)(pSeer->player.position.x)][(int)(pSeer->player.position.y - pSeer->player.direction.y
                                                                                                          * moveSpeed)]))
        pSeer->player.position.y -= pSeer->player.direction.y * moveSpeed;
}

void	move_left(t_seer *pSeer, double moveSpeed)
{
	double	new_x;
	double	new_y;

	new_x = pSeer->player.position.x - pSeer->camera.plane.x * moveSpeed;
	new_y = pSeer->player.position.y - pSeer->camera.plane.y * moveSpeed;
	if (can_move(pSeer->map_info.map_2d[(int)new_x][(int)pSeer->player.position.y]))
        pSeer->player.position.x = new_x;
	if (can_move(pSeer->map_info.map_2d[(int)pSeer->player.position.x][(int)new_y]))
        pSeer->player.position.y = new_y;
}

void	move_right(t_seer *pSeer, double moveSpeed)
{
	double	new_x;
	double	new_y;

	new_x = pSeer->player.position.x + pSeer->camera.plane.x * moveSpeed;
	new_y = pSeer->player.position.y + pSeer->camera.plane.y * moveSpeed;
	if (can_move(pSeer->map_info.map_2d[(int)new_x][(int)pSeer->player.position.y]))
        pSeer->player.position.x = new_x;
	if (can_move(pSeer->map_info.map_2d[(int)pSeer->player.position.x][(int)new_y]))
        pSeer->player.position.y = new_y;
}

static bool	can_move(char block)
{
	int			i;
	const char	*allowed_blocks;

	allowed_blocks = "0NSWEP";
	i = -1;
	while (allowed_blocks[++i])
		if (block == allowed_blocks[i])
			return (true);
	return (false);
}
