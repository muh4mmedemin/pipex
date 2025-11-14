# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muh4mmedemin <muh4mmedemin@student.42>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:54:22 by muh4mmedemin      #+#    #+#              #
#    Updated: 2025/11/06 11:54:22 by muh4mmedemin     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
#CFLAGS = -Wall -Wextra -Werror

SRCS = src/executer/exec.c src/parser/parser.c

DIRFOLDER = libs/ft_printf
DIRFOLDER2 = libs/libft

LIBS = libs/ft_printf/libftprintf.a
LIBS2 = libs/libft/libft.a

OBJS = $(SRCS:.c=.o)

all: rom $(NAME)

$(NAME): $(OBJS)
	$(CC) -lreadline -lhistory -lncurses  $(CFLAGS) $(OBJS)  $(LIBS) $(LIBS2) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -s -C $(DIRFOLDER) clean
	make -s -C $(DIRFOLDER2) clean

fclean: clean
	rm -f $(NAME)
	make -s -C $(DIRFOLDER) fclean
	make -s -C $(DIRFOLDER2) fclean

re: fclean all

rom:
	make -C $(DIRFOLDER)
	make -C $(DIRFOLDER2)

.PHONY: all clean fclean re