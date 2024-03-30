cmake_minimum_required(VERSION 3.25.1)
project(doomcraft)
set(CMAKE_C_STANDARD 99)

# Set the path to the MLX42 library
set(MLX_LIB ${CMAKE_CURRENT_SOURCE_DIR}/MLX42/build/libmlx42.a)

# Set the path to the MLX42 library build directory
set(MLX42_BUILD_DIR ${MLX42_SOURCE_DIR}/build)

# Add your project's source files
set(SOURCES
	main.c
	libft/fatal.c
	libft/ft_atoi.c
	libft/ft_calloc.c
	libft/ft_memcpy.c
	libft/ft_memset.c
	libft/ft_split.c
	libft/ft_strchr.c
	libft/ft_strcmp.c
	libft/ft_strdup.c
	libft/ft_strlen.c
	libft/ft_strnstr.c
	libft/ft_strrchr.c
	libft/ft_strtrim.c
	libft/ft_substr.c
	libft/get_next_line.c
	libft/split_utils.c
	srcs/helpers.c
	srcs/hooks.c
	srcs/inits.c
	srcs/move.c
	srcs/parsing/map_validity.c
	srcs/parsing/parsing.c
	srcs/parsing/utils.c
	srcs/parsing/colors.c
	srcs/parsing/map.c
	srcs/raycasting.c
	srcs/textures.c
	srcs/utils.c
	srcs/view.c
)

# Create the executable target
add_executable(doomcraft ${SOURCES})

# Link the executable with the MLX42 library
target_link_libraries(doomcraft PRIVATE ${MLX_LIB})

# Optionally, link other libraries depending on the OS
if(UNIX AND NOT APPLE)
    target_link_libraries(doomcraft PRIVATE dl glfw pthread m)
else()
    target_link_libraries(doomcraft PRIVATE glfw)
endif()

# Add any additional include directories if needed
target_include_directories(doomcraft PRIVATE includes MLX42/include/MLX42)

# Set compiler options
target_compile_options(doomcraft PRIVATE -Wall -Wextra -Werror)
