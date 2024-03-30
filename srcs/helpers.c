#include "../includes/doomcraft.h"

void	free_array(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
