# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:23:39 by pevieira          #+#    #+#              #
#    Updated: 2023/05/05 17:43:21 by pevieira         ###   ########.fr        #
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
SRC_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HDR = -I.
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(FLAGS) $(HDR) -c $< -o $@

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

test: all bonus
	$(CC) $(FLAGS) $(HDR) -c main.c -o main.o
	$(CC) $(FLAGS) -o output main.o -L. -lft
	./output
 
cleantest: fclean
	$(RM) output main.o
 
.PHONY: all bonus clean fclean re
