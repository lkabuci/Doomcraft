//
// Created by redone on 7/27/23.
//

#include "libft.h"
#include "mario.h"

void    *ft_calloc(int size)
{
    void    *buffer;
    int     i;

    i = 0;
    buffer = malloc(size);
    if (buffer == NULL)
        fatal("can't allocate memory.");
    while (i < size)
    {
        ((char*)buffer)[i] = 0;
        i++;
    }
    return (buffer);
}
