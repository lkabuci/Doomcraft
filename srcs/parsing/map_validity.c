//
// Created by redone on 7/29/23.
//

#include "../../includes/doomcraft.h"

/*
 * 1 -> only 6 possible characters (0, 1, N, S, E, W) and \0
 * 2 -> only one player position
 * 3 -> surrounded by walls (1)
 * 4 -> each space should be surrounded by walls (1) or spaces
 * 5 -> each 0 should be surrounded by walls (1) or other (0)
 */

void	check_borders(char *line);
void	check_wholes(t_map_info *pInfo, char **line, int row, int column);
void	setup_player(t_player *pPlayer, char direction, int row, int column);
void	setup_player_direction(t_player *pPlayer, char direction);

void	check_map(t_map_info *pInfo, char **pString)
{
	int	i;
	int	j;

	i = -1;
	while (pString[++i])
	{
		j = -1;
		while (pString[i][++j])
		{
			if (ft_strchr("01NEWS ", pString[i][j]) == NULL)
				fatal(ERR_INVALID_CHAR);
			if (ft_strchr("NEWS", pString[i][j]) != NULL)
				setup_player(&pInfo->seer->player, pString[i][j], i, j);
			check_borders(pString[i]);
			if (pString[i][j] == '0' || ft_strchr("NEWS", pString[i][j]))
				check_wholes(pInfo, pString, i, j);
		}
	}
	if (pInfo->seer->player.first_view == 0)
		fatal(ERR_N_PLAYER);
}

void	setup_player(t_player *pPlayer, char direction, int row, int column)
{
	static bool	is_player_found;

	is_player_found = false;
	if (is_player_found)
		fatal(ERR_M_PLAYER);
	is_player_found = true;
	pPlayer->position.x = row;
	pPlayer->position.y = column;
	pPlayer->first_view = direction;
	setup_player_direction(pPlayer, direction);
}

// TODO: Play with these values to get the right result
void	setup_player_direction(t_player *pPlayer, char direction)
{
	if (direction == 'N')
	{
		pPlayer->direction = (t_vector){-1.0, 0.0};
		pPlayer->seer->camera.plane = (t_vector){0.0, 0.66};
	}
	else if (direction == 'E')
	{
		pPlayer->direction = (t_vector){0.0, 1.0};
		pPlayer->seer->camera.plane = (t_vector){0.66, 0};
	}
	else if (direction == 'W')
	{
		pPlayer->direction = (t_vector){0.0, -1.0};
		pPlayer->seer->camera.plane = (t_vector){-0.66, 0};
	}
	else if (direction == 'S')
	{
		pPlayer->direction = (t_vector){1.0, 0.0};
		pPlayer->seer->camera.plane = (t_vector){0.0, -0.66};
	}
}

void	check_borders(char *line)
{
	char	*trimed_line;

	trimed_line = ft_strtrim(line, " ");
	if (trimed_line[0] != '1' || trimed_line[ft_strlen(trimed_line) - 1] != '1')
		fatal(ERR_NO_WALLS);
	free(trimed_line);
	trimed_line = NULL;
}

void	check_wholes(t_map_info *pInfo, char **line, int row, int column)
{
	if (row == 0 || row == pInfo->map_height - 1)
		fatal(ERR_NO_WALLS);
	if (column == 0 || column == pInfo->map_width - 1)
		fatal(ERR_NO_WALLS);
	if (line[row - 1][column] == ' ' || line[row + 1][column] == ' ')
		fatal(ERR_WHOLES);
	if (line[row][column - 1] == ' ' || line[row][column + 1] == ' ')
		fatal(ERR_WHOLES);
}
