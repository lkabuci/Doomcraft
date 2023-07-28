cmake_minimum_required(VERSION 3.25.1)
project(mario3D)
set(CMAKE_C_STANDARD 99)

add_executable(mario3D main.c
        srcs/parsing/parsing.c
        srcs/utils.c
        srcs/libft/get_next_line.c
        srcs/libft/ft_strjoin.c
        srcs/libft/ft_strlen.c
        srcs/libft/poinetrs.c
        srcs/libft/ft_substr.c
        srcs/libft/ft_strdup.c
        srcs/libft/ft_calloc.c
        srcs/libft/ft_strchr.c)
include_directories(mario3D includes)

target_compile_options(mario3D PRIVATE -Wall -Wextra)
