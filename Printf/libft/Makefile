# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:23:39 by pevieira          #+#    #+#              #
#    Updated: 2023/05/18 15:44:05 by pevieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PART_1 = ft_isalpha.c ft_bzero.c ft_atoi.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	 ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	 ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	 ft_strrchr.c ft_tolower.c ft_toupper.c
PART_2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC = $(PART_1) $(PART_2)
SRC_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HDR = -I.
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "libft.a created!"

all: $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS) $(OBJ)
	@echo "libft.a created with bonus"

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "Libft objects removed!"

fclean: clean
	@$(RM) $(NAME)
	@echo "libft.a removed!"

re: fclean all
	@echo "libft.a re-created!"

.PHONY: all bonus clean fclean re
