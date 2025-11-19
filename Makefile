# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 16:03:20 by muayna            #+#    #+#              #
#    Updated: 2025/11/19 16:03:20 by muayna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
#CFLAGS = -Wall -Wextra -Werror

SRCS = src/executer/executer.c src/parser/parser.c

DIRFOLDER = #libs/ft_printf
DIRFOLDER2 = #libs/libft

LIBS = #libs/ft_printf/libftprintf.a
LIBS2 = #libs/libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  $(LIBS) $(LIBS2) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re