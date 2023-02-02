# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:54:39 by acrespy           #+#    #+#              #
#    Updated: 2023/01/16 15:01:53 by acrespy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER_NAME = server
CLIENT_NAME = client

UTILS_SRCS = utils.c lists.c
SERVER_SRCS = server.c
CLIENT_SRCS = client.c

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

all:	${NAME}

${NAME}: ${SERVER_SRCS} ${CLIENT_SRCS} ${UTILS_SRCS}
	@${CC} ${CFLAGS} -o ${SERVER_NAME} ${SERVER_SRCS} ${UTILS_SRCS}
	@${CC} ${CFLAGS} -o ${CLIENT_NAME} ${CLIENT_SRCS} ${UTILS_SRCS}

clean:
	${RM} ${NAME}

fclean: clean

re:	fclean all

.PHONY: all bonus clean fclean re
