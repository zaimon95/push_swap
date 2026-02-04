NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP

SRCDIR := src
OBJDIR := build

SRC := $(SRCDIR)/main.c \
		$(SRCDIR)/parsing.c \
		$(SRCDIR)/operations.c \
		$(SRCDIR)/rotate.c \
		$(SRCDIR)/reverse_rotate.c \
		$(SRCDIR)/simple_sort.c \
		$(SRCDIR)/radix.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/index.c

OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


DEPS := $(OBJ:.o=.d)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(SRCDIR) -I.

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR) --no-print-directory

	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFT_DIR) --no-print-directory
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
