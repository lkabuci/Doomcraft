
#include "../includes/cray.h"

void	free_array(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

t_point	get_player_xy_position(char **realMap)
{
	int	x;
	int	y;

	x = -1;
	while (realMap[++x])
	{
		y = -1;
		while (realMap[x][++y])
		{
			if (ft_strchr("NEWSP", realMap[x][y]))
				return ((t_point){x, y});
		}
	}
	fatal("No player found");
	return ((t_point){-1, -1});
}

t_vector	get_first_player_direction(t_seer *pSeer, char direction)
{
	t_vector	dir;

	dir = (t_vector){0.0, -1.0};
    pSeer->camera.plane.x = -0.66;
    pSeer->camera.plane.y = 0;
	if (direction == 'N')
	{
		dir = (t_vector){-1.0, 0.0};
        pSeer->camera.plane.x = 0;
        pSeer->camera.plane.y = 0.66;
	}
	else if (direction == 'S')
	{
		dir = (t_vector){1.0, 0.0};
        pSeer->camera.plane.x = 0;
        pSeer->camera.plane.y = -0.66;
	}
	else if (direction == 'E')
	{
		dir = (t_vector){0.0, 1.0};
        pSeer->camera.plane.x = 0.66;
        pSeer->camera.plane.y = 0;
	}
	return (dir);
}
