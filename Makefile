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

DIRFOLDER = libs/ft_printf
DIRFOLDER2 = libs/libft
DIRFOLDER3 = libs/garbage_collector

LIBS = libs/ft_printf/libftprintf.a
LIBS2 = libs/libft/libft.a
LIBS3 = libs/garbage_collector/libgb.a

OBJS = $(SRCS:.c=.o)

all: rom $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  $(LIBS) $(LIBS2) $(LIBS3) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(DIRFOLDER) clean
	make -C $(DIRFOLDER2) clean
	make -C $(DIRFOLDER3) clean

fclean: clean
	rm -f $(NAME)
	make -C $(DIRFOLDER) fclean
	make -C $(DIRFOLDER2) fclean
	make -C $(DIRFOLDER3) fclean

re: fclean all

rom:
	make -C $(DIRFOLDER)
	make -C $(DIRFOLDER2)
	make -C $(DIRFOLDER3)

.PHONY: all clean fclean re