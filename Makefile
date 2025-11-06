CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC_SERVER = server.c
SRC_CLIENT = client.c
PRINTF_DIR = ./printf
LIBFT_DIR = ./libft
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

all: server client

server: $(OBJS_SERVER) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) $(LIBFT) -o $@

client: $(OBJS_CLIENT) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) $(LIBFT) -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f server client
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean
re: fclean all
