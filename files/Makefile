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

UTILS_SRCS = utils.c
SERVER_SRCS = server.c
CLIENT_SRCS = client.c

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

all:	${NAME}

${NAME}: ${SERVER_SRCS} ${CLIENT_SRCS}
	@${CC} ${CFLAGS} -o server ${SERVER_SRCS} ${UTILS_SRCS}
	@${CC} ${CFLAGS} -o client ${CLIENT_SRCS} ${UTILS_SRCS}

clean:
	${RM} ${NAME}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re
