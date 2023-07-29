//
// Created by redone on 7/27/23.
//

#include "cray.h"

void    fatal(const char *msg)
{
    write(2, "Error: ", 7);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
    exit (EXIT_FAILURE);
}
