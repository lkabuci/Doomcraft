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
#include <stdbool.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

void    *ft_calloc(int size);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, int c);
char *ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char *get_next_line(int fd);
void    free_ptr(void **ptr);
void*   ft_memset(void *b, int c, size_t len);
void*   ft_memcpy(void *dst, const void *src, size_t n);
void    free_array(char **array);
int	ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *str, char *charset);
int	ft_atoi(const char *str);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strnstr(char *haystack, char *needle, size_t len);

#endif //MARIO3D_LIBFT_H
