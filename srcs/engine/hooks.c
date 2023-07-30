//
// Created by redone on 7/30/23.
//

#include "cray.h"

void process_mouvement(void *params)
{
    t_seer *seer;

    seer = (t_seer *) params;
    if (mlx_is_key_down(seer->mlx, MLX_KEY_ESCAPE))
        exit(0);
}
