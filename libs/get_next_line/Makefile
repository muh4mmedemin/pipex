# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 23:05:24 by muayna            #+#    #+#              #
#    Updated: 2025/12/04 23:05:24 by muayna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re