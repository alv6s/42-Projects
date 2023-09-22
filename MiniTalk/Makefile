# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 13:36:02 by pevieira          #+#    #+#              #
#    Updated: 2023/09/22 14:03:02 by pevieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
NAMELIBFT = libft/libft.a

SRC_C = src/client.c
SRC_S = src/server.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

all:	${NAME}

${NAMELIBFT}:
		${MAKE} ${LIBFT_PATH} all

${NAME}: ${NAMELIBFT}
		${CC} ${CFLAGS} ${SRC_C} ${INCLUDE} ${NAMELIBFT} -o client
		${CC} ${CFLAGS} ${SRC_S} ${INCLUDE} ${NAMELIBFT} -o server

$(NAMELIBFT): ${OBJS}
		${MAKE} ${LIBFT_PATH} all

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} -rf client server

re: fclean all

.PHONY: all clean fclean re