CFLAGS = -Wall -Wextra -Werror
CC = cc

NAME1 = server
NAME2 = client
SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

OBJS_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $@

$(NAME2): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $@

bonus: server_bonus client_bonus

server_bonus: $(OBJS_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) -o server

client_bonus: $(OBJS_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) -o client
$(LIBFT):
	make -C $(LIBFT_DIR)
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f server client
	make -C $(LIBFT_DIR) fclean
re: fclean all
