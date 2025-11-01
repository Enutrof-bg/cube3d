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

FILE = main_test.c \
test_check_map.c \
ft_itoa.c \
ft_split.c\
ft_strjoin.c\
ft_strdup.c\
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
# 	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} -o $@

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
	${DIRGNL}/get_next_line.o \
	${DIRGNL}/get_next_line_utils.o
# 	make fclean -C ft_printf
# 	make fclean -C minilibx-linux

fclean: clean
	rm -f cube

re: fclean
	make
