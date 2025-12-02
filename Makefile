# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 11:35:24 by sla-gran          #+#    #+#              #
#    Updated: 2025/12/01 11:35:24 by sla-gran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc

SRC := 	push_swap.c

CFLAGS := -Wall -Wextra -Werror

OBJ := $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ -I libft/

clean :
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
