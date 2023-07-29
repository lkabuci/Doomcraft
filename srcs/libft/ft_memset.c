//
// Created by redone on 7/28/23.
//

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;

    ptr = (unsigned char *)b;
    while (len--)
        *ptr++ = (unsigned char)c;
    return (b);
}
