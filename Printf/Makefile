# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:23:39 by pevieira          #+#    #+#              #
#    Updated: 2023/05/13 16:14:11 by pevieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HDR = -I .
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = Libft
LIBFT = $(LIBFT_PATH)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
 
.PHONY: all bonus clean fclean re
