NAME_SERVER = server
NAME_CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS)  $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)
$(PRINTF):
	make -C $(PRINTF_DIR)
clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: clean all

.PHONY: all clean re
