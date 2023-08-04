//
// Created by redone on 7/27/23.
//

#include "libft.h"

void    free_ptr(void **ptr)
{
    if (*ptr == NULL)
        return;
    free(*ptr);
    *ptr = NULL;
}

int	ft_split_len(char **elements)
{
	int	i;

	i = -1;
	while (elements[++i])
		;
	return (i);
}

void    free_array(char **array)
{
    int i;

    i = 0;
    if (array == NULL)
        return;
    while (array[i])
    {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    free(array);
    array = NULL;
}
