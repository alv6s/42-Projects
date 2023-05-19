# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:23:39 by pevieira          #+#    #+#              #
#    Updated: 2023/05/18 21:16:44 by pevieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_basics.c ft_uitoa.c ft_hexa.c
OBJ = $(SRC:.c=.o)
HDR = -I .
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) $(HDR) -c $< -o $@
 
$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "libftprintf.a created!"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@make clean -C libft
	@echo "libftprintf objects removed!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@echo "libftprintf.a removed!"
	
re: fclean all
	@echo "libftprintf.a re-created!"

test:
	@$(CC) $(CFLAGS) $(HDR) -c main.c -o main.o 
	@$(CC) $(CFLAGS) -o output main.o -L . -lftprintf
	@echo "Test:"
	@./output
	@rm output
	@rm main.o

.PHONY: all bonus clean fclean re
