# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 11:20:17 by kevwang           #+#    #+#              #
#    Updated: 2025/11/05 16:16:31 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes
HEADERS = includes/cube.h

#LIBRARIES
MLX = -Lminilibx-linux -lmlx -lX11 -lXext -lm 
DIRPRINT = ft_printf
INCPRINTF = -Lft_printf -lftprintf

#PATH
RAY_PATH = raycasting/
SRC_PATH = sources/

FILE = main_test.c \
ft_itoa.c \
ft_time.c \
movement.c \
movement_rotate.c \
ft_free.c \
ft_realloc_map.c \
init_dir.c \
raycasting.c \
minimap.c \
print_pixel.c \
movement.c \
movement_rotate.c \
movement_side.c \
init_texture.c \
init_texture_anim.c \
init_texture_door.c \
init_texture_wall.c \
raycasting.c \
raycasting_calculate.c \
raycasting_render.c \
raycasting_door.c \
ft_print_debug.c \
hook.c \
open_door.c \
init_value.c \
mouse.c

SRC_FILES = check_valid_map_2.c check_valid_map.c free.c get_next_line_utils.c \
			get_next_line.c init.c main.c parsing_colours.c parsing_directions.c \
			parsing_loading_map.c parsing_map_char.c parsing_map.c utils.c utils_2.c \
			check_valid_map_3.c
			
SRC_FILES_BONUS = check_valid_map_2.c check_valid_map.c free.c get_next_line_utils.c \
				get_next_line.c init.c main.c parsing_colours.c parsing_directions.c \
				parsing_loading_map.c parsing_map_char_bonus.c parsing_map.c utils.c utils_2.c check_valid_map_3.c
				
BONUS_FILE = print_anim_bonus.c hook_bonus.c \
main_test.c \
ft_itoa.c \
ft_time.c \
movement.c \
movement_rotate.c \
ft_free.c \
ft_realloc_map.c \
init_dir.c \
raycasting.c \
minimap.c \
print_pixel.c \
movement.c \
movement_rotate.c \
movement_side.c \
init_texture.c \
init_texture_anim.c \
init_texture_door.c \
init_texture_wall.c \
raycasting.c \
raycasting_calculate.c \
raycasting_render.c \
raycasting_door.c \
ft_print_debug.c \
open_door.c \
init_value.c \
mouse.c
				
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES)) $(addprefix $(RAY_PATH), $(FILE))
OBJS = $(patsubst %.c,%.o,$(SRC))

SRC_BONUS = $(addprefix $(SRC_PATH), $(SRC_FILES_BONUS)) $(addprefix $(RAY_PATH), $(BONUS_FILE))
OBJS_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))

NAME = cube
NAME_BONUS = cube_bonus

all: ${NAME}

${NAME} : ${OBJS}
	make -C minilibx-linux
	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} ${INCPRINTF} -o $@

${NAME_BONUS} : ${OBJS_BONUS}
	make -C minilibx-linux
	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} ${INCPRINTF} -o $@

%.o:%.c $(HEADERS)
	${CC} ${CFLAGS} -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make fclean -C ft_printf
	make clean -C minilibx-linux

fclean: clean
	rm -f cube
	rm -f cube_bonus 

re: fclean all
