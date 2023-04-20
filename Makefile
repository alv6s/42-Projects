# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:23:39 by pevieira          #+#    #+#              #
#    Updated: 2023/04/19 20:11:20 by pevieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_bzero.c ft_atoi.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	 ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	 ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	 ft_strrchr.c ft_tolower.c ft_toupper.c
SRC_BONUS = 
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
INCLUDE = -I . 
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror


%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS) $(OBJ)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
