# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 11:35:24 by sla-gran          #+#    #+#              #
#    Updated: 2026/01/29 11:50:13 by sla-gran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC := main.c \
       parsing.c \
<<<<<<< HEAD
       push_swap.c \
       operations.c \
       rotate.c \
	   reverse_rotate.c \
	   algo.c
=======
       operations.c \
       rotate.c \
       reverse_rotate.c \
       simple_sort.c \
       radix.c \
       utils.c \
			 index.c
>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1

OBJ := $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
