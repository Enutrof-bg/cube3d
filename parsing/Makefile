# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 13:34:02 by vafavard          #+#    #+#              #
#    Updated: 2025/11/02 16:38:11 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC_PATH = sources/

SRC_FILES = check_valid_map_2.c check_valid_map.c free.c get_next_line_utils.c \
			get_next_line.c init.c main.c parsing_colours.c parsing_directions.c \
			parsing_loading_map.c parsing_map_char.c parsing_map.c utils.c utils_2.c \
			check_valid_map_3.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(patsubst %.c,%.o,$(SRC))
INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)


%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
