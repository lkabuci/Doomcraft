//
// Created by redone on 7/27/23.
//

#include "libft.h"

void    free_ptr(void **ptr)
{
    if (*ptr == NULL)
        return;
    free(*ptr);
    ptr = NULL;
}

void    free_array(char **array)
{
    int i;

    i = 0;
    if (array == NULL)
        return;
    while (array[i])
    {
        free_ptr(array[i]);
        i++;
    }
    free_ptr(array);
}
