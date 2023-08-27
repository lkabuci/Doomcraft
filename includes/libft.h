#ifndef LIBFT_H
# define LIBFT_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_strdup(char *str);
char	*get_next_line(int fd);
void	*ft_calloc(size_t size);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	fatal(const char *message);
int		ft_split_len(char **elements);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char *str, char *charset);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif /* LIBFT_H */
