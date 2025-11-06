NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_printf.c \
ft_putnbr_uns.c \
ft_print_hexa.c \
ft_print_pointer.c \
ft_strchr.c

OBJS = ft_putchar.o ft_putstr.o ft_putnbr.o ft_printf.o ft_putnbr_uns.o ft_print_hexa.o ft_print_pointer.o ft_strchr.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

ft_putchar.o: ft_putchar.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_putchar.c -o ft_putchar.o

ft_putstr.o: ft_putstr.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_putstr.c -o ft_putstr.o

ft_putnbr.o: ft_putnbr.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_putnbr.c -o ft_putnbr.o

ft_printf.o: ft_printf.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_printf.c -o ft_printf.o
	
ft_putnbr_uns.o: ft_putnbr_uns.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_putnbr_uns.c -o ft_putnbr_uns.o
	
ft_print_hexa.o: ft_print_hexa.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_print_hexa.c -o ft_print_hexa.o

ft_print_pointer.o: ft_print_pointer.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_print_pointer.c -o ft_print_pointer.o

ft_strchr.o: ft_strchr.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_strchr.c -o ft_strchr.o

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
