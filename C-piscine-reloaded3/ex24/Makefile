# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 21:45:18 by oduran-m          #+#    #+#              #
#    Updated: 2025/12/15 22:48:50 by oduran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = gcc
HD = ./includes/
CFLAGS = -Wall -Werror -Wextra -I $(HD)
DIRF =	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_strcmp.c \
	srcs/ft_strlen.c \
	srcs/ft_swap.c
NAME_DIR = libft.a
OBJS = $(DIRF:.c=.o)

all: $(NAME_DIR)

$(NAME_DIR): $(OBJS)
	ar rcs $(NAME_DIR) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME_DIR)

re: fclean all

.PHONY: all clean fclean re
