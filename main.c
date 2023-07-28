//
// Created by redone on 7/27/23.
//

#include "mario.h"

int main ()
{
    int fd = open("/home/redone/Projects/cRay/README.md", O_RDONLY);
    if (fd < 0) {
        puts("in");
        return 1;
    }
    while (1)
    {
        char *line = get_next_line(fd);
        if (line == NULL)
            break;
        puts(line);
        free_ptr((void **) &line);
    }

    return 0;
}
