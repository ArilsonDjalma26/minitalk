# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalbano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 12:11:56 by aalbano           #+#    #+#              #
#    Updated: 2025/07/04 17:31:46 by aalbano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
FLAGS   = -Wall -Wextra -Werror
SRC     = .
INC_DIR = .
INC     = -I$(INC_DIR)
AR      = ar rcs
RM      = rm -f
HEADER  = libft.h
NAME    = libft.a
SRCS = \
	$(SRC)/ft_atoi.c \
	$(SRC)/ft_bzero.c \
	$(SRC)/ft_calloc.c \
	$(SRC)/ft_isalnum.c \
	$(SRC)/ft_isalpha.c \
	$(SRC)/ft_isascii.c \
	$(SRC)/ft_isdigit.c \
	$(SRC)/ft_isprint.c \
	$(SRC)/ft_itoa.c \
	$(SRC)/ft_memchr.c \
	$(SRC)/ft_memcmp.c \
	$(SRC)/ft_memcpy.c \
	$(SRC)/ft_memmove.c \
	$(SRC)/ft_putchar_fd.c \
	$(SRC)/ft_memset.c \
	$(SRC)/ft_putendl_fd.c \
	$(SRC)/ft_putnbr_fd.c \
	$(SRC)/ft_putstr_fd.c \
	$(SRC)/ft_split.c \
	$(SRC)/ft_strchr.c \
	$(SRC)/ft_strdup.c \
	$(SRC)/ft_striteri.c \
	$(SRC)/ft_strjoin.c \
	$(SRC)/ft_strlcat.c \
	$(SRC)/ft_strlcpy.c \
	$(SRC)/ft_strlen.c \
	$(SRC)/ft_strmapi.c \
	$(SRC)/ft_strncmp.c \
	$(SRC)/ft_strnstr.c \
	$(SRC)/ft_strrchr.c \
	$(SRC)/ft_strtrim.c \
	$(SRC)/ft_substr.c \
	$(SRC)/ft_tolower.c \
	$(SRC)/ft_toupper.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
$(SRC)/ft_atoi.o: $(SRC)/ft_atoi.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_bzero.o: $(SRC)/ft_bzero.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_calloc.o: $(SRC)/ft_calloc.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_isalnum.o: $(SRC)/ft_isalnum.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_isalpha.o: $(SRC)/ft_isalpha.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_isascii.o: $(SRC)/ft_isascii.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_isdigit.o: $(SRC)/ft_isdigit.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_isprint.o: $(SRC)/ft_isprint.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_itoa.o: $(SRC)/ft_itoa.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_memchr.o: $(SRC)/ft_memchr.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_memcmp.o: $(SRC)/ft_memcmp.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_memcpy.o: $(SRC)/ft_memcpy.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_memmove.o: $(SRC)/ft_memmove.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_putchar_fd.o: $(SRC)/ft_putchar_fd.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_memset.o: $(SRC)/ft_memset.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_putendl_fd.o: $(SRC)/ft_putendl_fd.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_putnbr_fd.o: $(SRC)/ft_putnbr_fd.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_putstr_fd.o: $(SRC)/ft_putstr_fd.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_split.o: $(SRC)/ft_split.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strchr.o: $(SRC)/ft_strchr.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strdup.o: $(SRC)/ft_strdup.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_striteri.o: $(SRC)/ft_striteri.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strjoin.o: $(SRC)/ft_strjoin.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strlcat.o: $(SRC)/ft_strlcat.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strlcpy.o: $(SRC)/ft_strlcpy.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strlen.o: $(SRC)/ft_strlen.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strmapi.o: $(SRC)/ft_strmapi.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strncmp.o: $(SRC)/ft_strncmp.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strnstr.o: $(SRC)/ft_strnstr.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strrchr.o: $(SRC)/ft_strrchr.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_strtrim.o: $(SRC)/ft_strtrim.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_substr.o: $(SRC)/ft_substr.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_tolower.o: $(SRC)/ft_tolower.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
$(SRC)/ft_toupper.o: $(SRC)/ft_toupper.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
