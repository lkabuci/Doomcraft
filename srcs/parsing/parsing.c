//
// Created by redone on 7/27/23.
//

#include "cray.h"

void    parse_elements(char *map_filename, t_map_info *info);

void    parsing(t_seer *seer, char *map_filename)
{
    if (seer != NULL)
        (void)seer;
    parse_elements(map_filename, NULL);
}

void    parse_elements(char *map_filename, t_map_info *info)
{
    int fd;

    (void)info;
    printf("in\n");
    fd = open(map_filename, O_RDONLY);
    if (fd == -1)
        fatal("Can't open the file");
}
