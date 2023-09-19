# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 15:47:54 by pevieira          #+#    #+#              #
#    Updated: 2023/09/19 16:04:20 by pevieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = commands_1.c commands_2.c error_cases.c main.c set_node_infos.c \
		sort_big_algorithm.c sort_small_algorithm.c stack_creation.c stack_utils.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re