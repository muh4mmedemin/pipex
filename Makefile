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

SRCS = src/executer/executer.c src/parser/parser.c src/main/main.c src/parser/error.c src/main/main_utils.c libs/get_next_line/get_next_line.c

DIRFOLDER = libs/ft_printf
DIRFOLDER2 = libs/libft
DIRFOLDER3 = libs/garbage_collector
DIRFOLDER4 = libs/get_next_line

LIBS = libs/ft_printf/libftprintf.a
LIBS2 = libs/libft/libft.a
LIBS3 = libs/garbage_collector/libgb.a
LIBS4 = libs/get_next_line/gnl.a

OBJS = $(SRCS:.c=.o)

all: rom $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  $(LIBS) $(LIBS2) $(LIBS3) $(LIBS4) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(DIRFOLDER) clean
	make -C $(DIRFOLDER2) clean
	make -C $(DIRFOLDER3) clean
	make -C $(DIRFOLDER4) clean

fclean: clean
	rm -f $(NAME)
	make -C $(DIRFOLDER) fclean
	make -C $(DIRFOLDER2) fclean
	make -C $(DIRFOLDER3) fclean
	make -C $(DIRFOLDER4) fclean

re: fclean all

rom:
	make -C $(DIRFOLDER)
	make -C $(DIRFOLDER2)
	make -C $(DIRFOLDER3)
	make -C $(DIRFOLDER4)

.PHONY: all clean fclean re