# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:40:01 by pevieira          #+#    #+#              #
#    Updated: 2023/09/07 15:58:30 by pevieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = command_push.c/command_reverse_rotate.c/command_rotate.c/command_swap.c/push_swap.c \
		/sort_big.c/sort_tiny.c/sort_utils_info_reset.c/stack_creation.c/stack_utils_2.c/stack_utils.c

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