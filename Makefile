CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf
MKDIR		=	mkdir -p

COMPILING	=	-I MLX42/include
MLX42		=	MLX42
MLX_LIB		=	MLX42/build/libmlx42.a

OS	        =	$(shell uname -s)

ifeq ($(OS),Linux)
    LINKING =	$(MLX_LIB) -ldl -lglfw -pthread -lm
else
    LINKING =	$(MLX_LIB) -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
endif

SRCS		=	main.c libft/fatal.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_split.c libft/ft_strchr.c libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_strnstr.c libft/get_next_line.c libft/split_utils.c srcs/inits.c srcs/parsing/map_validity.c srcs/parsing/parsing.c srcs/parsing/utils.c srcs/hooks.c srcs/move.c srcs/raycasting.c srcs/textures.c srcs/utils.c srcs/view.c srcs/helpers.c

SRCS_DIRS   = $(dir $(SRCS))

BIN_DIR     = bin/

OBJS        = $(SRCS:%.c=$(BIN_DIR)%.o)
OBJS_DIRS   = $(dir $(OBJS))

INCLUDES	=	includes/libft.h includes/cray.h

NAME		=	cRay

all: $(NAME)

$(MLX_LIB):
	@cmake $(MLX42) -B $(MLX42)/build
	@make -C $(MLX42)/build -j4

$(NAME):    $(OBJS) $(MLX_LIB)
	@$(CC) $(CFLAGS) $^ $(LINKING) -o $@

$(BIN_DIR)%.o:  %.c $(INCLUDES) $(MLX_LIB)
	@$(MKDIR) $(OBJS_DIRS)
	$(CC) $(CFLAGS) $(COMPILING) -c $< -o $@

clean:
	$(RM) $(BIN_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB) $(MLX42)/build

re: fclean all
