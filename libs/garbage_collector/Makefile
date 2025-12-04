# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 23:05:13 by muayna            #+#    #+#              #
#    Updated: 2025/12/04 23:05:14 by muayna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgb.a

C_FILES = ./gb.c
INC = -I./

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

CC = cc
W_FLAGS = -Wall -Wextra -Werror
CC_ARGS = $(W_FLAGS) $(INC)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $?

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CC_ARGS) $? -c -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
