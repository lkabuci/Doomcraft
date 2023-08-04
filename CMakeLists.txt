cmake_minimum_required(VERSION 3.25.1)
project(cRay)
set(CMAKE_C_STANDARD 99)

# Set the path to the MLX42 library
set(MLX_LIB ${CMAKE_CURRENT_SOURCE_DIR}/MLX42/build/libmlx42.a)

# Set the path to the MLX42 library build directory
set(MLX42_BUILD_DIR ${MLX42_SOURCE_DIR}/build)

# Add your project's source files
set(SOURCES
    main.c
    srcs/parsing/parsing.c
    srcs/utils.c
    srcs/libft/get_next_line.c
    srcs/libft/ft_strjoin.c
    srcs/libft/ft_strlen.c
    srcs/libft/poinetrs.c
    srcs/libft/ft_substr.c
    srcs/libft/ft_strdup.c
    srcs/libft/ft_calloc.c
    srcs/libft/ft_strchr.c
    srcs/libft/ft_split.c
        srcs/parsing/utils.c
        srcs/libft/ft_memset.c
        srcs/libft/ft_memcpy.c
        srcs/libft/ft_strcmp.c
        srcs/libft/ft_atoi.c
        srcs/libft/types.c
        srcs/parsing/map_validity.c
        srcs/libft/ft_strtrim.c
        srcs/engine/raycasting.c
        srcs/engine/hooks.c
        freeing.c
        srcs/engine/render.c
        srcs/engine/shapes.c
        srcs/vectors/operation.c
        srcs/vectors/normalize.c
        srcs/libft/ft_strnstr.c
)

# Create the executable target
add_executable(cRay ${SOURCES})

# Link the executable with the MLX42 library
target_link_libraries(cRay PRIVATE ${MLX_LIB})

# Optionally, link other libraries depending on the OS
if(UNIX AND NOT APPLE)
    target_link_libraries(cRay PRIVATE dl glfw pthread m)
else()
    target_link_libraries(cRay PRIVATE glfw)
endif()

# Add any additional include directories if needed
target_include_directories(cRay PRIVATE includes MLX42/include/MLX42)

# Set compiler options
# TODO: add -Werror later
target_compile_options(cRay PRIVATE -Wall -Wextra)
