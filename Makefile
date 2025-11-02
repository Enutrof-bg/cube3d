# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 11:20:17 by kevwang           #+#    #+#              #
#    Updated: 2025/10/27 11:20:19 by kevwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX = -Lminilibx-linux -lmlx -lX11 -lXext -lm 
DIRGNL = gnl
DIRPRINT = ft_printf

INCPRINTF = -Lft_printf -lftprintf

FILE = main_test.c \
test_check_map.c \
ft_itoa.c \
ft_split.c\
ft_strjoin.c\
ft_strdup.c\
ft_time.c \
movement.c \
movement_rotate.c \
ft_free.c \
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
init_texture_minimap.c \
raycasting.c \
raycasting_calculate.c \
raycasting_render.c \
raycasting_door.c \
ft_print_debug.c \
hook.c \
open_door.c \
init_value.c \
${DIRGNL}/get_next_line.c \
${DIRGNL}/get_next_line_utils.c \

#${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c \

SRC = ${FILE:.c=.o}

NAME = cube

FILEPRINTF = ${DIRPRINT}/ft_printf.o ${DIRPRINT}/ft_putcharstr.o ${DIRPRINT}/ft_puthexa.o \
${DIRPRINT}/ft_putnbr.o ${DIRPRINT}/ft_putptr.o ${DIRPRINT}/ft_putunsigned.o

all: ${NAME}

${NAME} : ${SRC} #${FILEPRINTF}
	make -C minilibx-linux
	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} ${INCPRINTF} -o $@

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f main_test.o \
	test_check_map.o \
	ft_itoa.o \
	ft_split.o \
	ft_strjoin.o \
	ft_strdup.o \
	ft_strdup.o \
	ft_time.o \
	movement.o \
	movement_rotate.o \
	ft_free.o \
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
	init_texture_minimap.o \
	raycasting.o \
	raycasting_calculate.o \
	raycasting_render.o \
	raycasting_door.o \
	ft_print_debug.o \
	hook.o \
	open_door.o \
	init_value.o \
	${DIRGNL}/get_next_line.o \
	${DIRGNL}/get_next_line_utils.o
	make fclean -C ft_printf
# 	make fclean -C minilibx-linux

fclean: clean
	rm -f cube

re: fclean all
