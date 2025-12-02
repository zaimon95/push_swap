NAME := libft.a

CC := cc

LIBFT := libft1.a

LIBFT_DIR := libft

SRC := 	ft_printf.c \
		ft_putvoid.c \
		ft_putnbr_base.c \
		ft_putnbr_unsigned.c 

CFLAGS := -Wall -Wextra -Werror

OBJ := $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR)/

clean :
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
