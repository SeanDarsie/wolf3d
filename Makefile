# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/22 12:39:45 by sdarsie           #+#    #+#              #
#    Updated: 2017/06/26 13:56:33 by sdarsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d
LIBFT = ./libft/libft.a
LIB_MLX = ./minilibx_macos/libmlx.a
LIBFTINC = -L ./libft/ -lft
INC = wolf3d.h
MINILIB = -L ./minilibx_macos/ -lmlx
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit


SRC_DIR = ./src/
FILES = main.c \
	find_walls.c \
	hooks.c \
	make_colors.c \
	more_hooks.c \
	world_map.c \
	move_thru_map.c \
	wall.c \
	world.c \

SRCS = $(addprefix $(SRC_DIR),$(FILES))

OBJ_DIR = ./obj/
OBJ_NAME = $(FILES:%.c=%.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

all: obj $(NAME)

$(NAME):  $(LIBFT) $(OBJS) $(LIB_MLX) $(INC)
	gcc -o $(NAME) $(OBJS) $(CFLAGS) $(MINILIB) $(LIBFTINC) $(FRAMEWORKS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(CFLAGS) -o $@ -c $<  

obj:
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C ./libft

$(LIB_MLX):
	make -C ./minilibx_macos

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./minilibx_macos

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all 
