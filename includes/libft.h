//
// Created by redone on 7/27/23.
//

#ifndef MARIO3D_LIBFT_H
#define MARIO3D_LIBFT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

void    *ft_calloc(int size);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str);
char *ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char *get_next_line(int fd);
void    free_ptr(void **ptr);
void    free_array(char **array);
char	**ft_split(char *s, char c);

#endif //MARIO3D_LIBFT_H
