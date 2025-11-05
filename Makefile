# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 11:20:17 by kevwang           #+#    #+#              #
#    Updated: 2025/11/05 16:00:57 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX = -Lminilibx-linux -lmlx -lX11 -lXext -lm 
DIRGNL = gnl
DIRPRINT = ft_printf

INCPRINTF = -Lft_printf -lftprintf
# INCCUBE = -Lparsing -lCub3d

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
print_anim.c \
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
mouse.c \
${DIRGNL}/get_next_line.c \
${DIRGNL}/get_next_line_utils.c \

SRC_PATH = parsing/sources/
SRC_FILES = check_valid_map_2.c check_valid_map.c free.c get_next_line_utils.c \
			get_next_line.c init.c main.c parsing_colours.c parsing_directions.c \
			parsing_loading_map.c parsing_map_char.c parsing_map.c utils.c utils_2.c \
			check_valid_map_3.c
			
SRC_FILES_BONUS = check_valid_map_2.c check_valid_map.c free.c get_next_line_utils.c \
				get_next_line.c init.c main.c parsing_colours.c parsing_directions.c \
				parsing_loading_map.c parsing_map_char_bonus.c parsing_map.c utils.c utils_2.c \
				check_valid_map_3.c
				
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
SRC_BONUS = $(addprefix $(SRC_PATH), $(SRC_FILES_BONUS))


OBJS = $(patsubst %.c,%.o,$(SRC))
OBJS_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))
INCLUDES = -Iincludes

SRC2 = ${FILE:.c=.o}

NAME = cube
NAME_BONUS = cube_bonus
FILEPRINTF = ${DIRPRINT}/ft_printf.o ${DIRPRINT}/ft_putcharstr.o ${DIRPRINT}/ft_puthexa.o \
${DIRPRINT}/ft_putnbr.o ${DIRPRINT}/ft_putptr.o ${DIRPRINT}/ft_putunsigned.o

all: ${NAME}

${NAME} : ${SRC2} ${OBJS}
	make -C minilibx-linux
	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} ${INCPRINTF} -o $@

${NAME_BONUS} : ${SRC2} ${OBJS_BONUS}
	make -C minilibx-linux
	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} ${INCPRINTF} -o $@

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)\
	main_test.o \
	ft_itoa.o \
	ft_time.o \
	movement.o \
	movement_rotate.o \
	ft_free.o \
	ft_realloc_map.o \
	init_dir.o \
	raycasting.o \
	minimap.o \
	print_pixel.o \
	print_anim.o \
	movement.o \
	movement_rotate.o \
	movement_side.o \
	init_texture.o \
	init_texture_anim.o \
	init_texture_door.o \
	init_texture_wall.o \
	raycasting.o \
	raycasting_calculate.o \
	raycasting_render.o \
	raycasting_door.o \
	ft_print_debug.o \
	hook.o \
	open_door.o \
	init_value.o \
	mouse.o \
	${DIRGNL}/get_next_line.o \
	${DIRGNL}/get_next_line_utils.o
	make fclean -C ft_printf
# 	make fclean -C minilibx-linux

fclean: clean
	rm -f cube
	rm -f cube_bonus 

re: fclean all
