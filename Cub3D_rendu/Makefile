# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apreymon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 22:03:59 by apreymon          #+#    #+#              #
#    Updated: 2020/05/11 15:34:26 by apreymon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINUX = yes
	
ifeq ($(LINUX), yes)
MLX_FLAGS = -lXext -lX11 -lm -lbsd
MLX_PATH = ./minilibx-linux-master/
else
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MLX_PATH = ./minilibx_opengl_20191021/
endif

NAME = Cub3D

INCL_PATH = ./include/
LIBFT_PATH = ./libft/

CC = clang-9
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

HEADER = cub3d.h \
		libft.h \
		mlx.h
FILES = main \
		get_settings \
		check_fd \
		check_map \
		parse_fd \
		parse_map \
		init_player \
		init_game \
		init_sprite \
		keyboard \
		camera \
		move \
		ray_h \
		ray_v \
		raycast \
		draw_map \
		draw_window \
		sprite_utils \
		draw_sprite \
		screenshot \
		textures \
		exit

SRCS = $(addsuffix .c, $(FILES))
SRCDIR = srcs/

OBJS = $(addsuffix .o, $(FILES))
OBJDIR = objs/

all: $(NAME)

$(NAME) : $(addprefix $(OBJDIR), $(OBJS))
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) -I $(INCL_PATH) $^ $(MLX_FLAGS) -o $@ ./minilibx-linux-master/libmlx.a ./libft/libft.a

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCL_PATH)) -c $^ -o $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	rm -f libft/libft.a
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
