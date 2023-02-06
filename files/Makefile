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

NAME        := minitalk

NAME_SERVER := server
NAME_CLIENT := client

SRC_DIR     := srcs
SRCS_SERVER := \
			server.c \
			utils.c  \
			lists.c  \

SRCS_CLIENT := \
			client.c \
			utils.c  \
			lists.c  \

SRCS_SERVER := ${SRCS_SERVER:%=${SRC_DIR}/%}
SRCS_CLIENT := ${SRCS_CLIENT:%=${SRC_DIR}/%}

OBJ_DIR     := .objs
OBJS_SERVER := ${SRCS_SERVER:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
OBJS_CLIENT := ${SRCS_CLIENT:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

CC          := clang
CFLAGS      := -Wall -Wextra -Werror

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p ${@D}

all: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${OBJS_SERVER}
	${CC} ${OBJS_SERVER} -o ${NAME_SERVER}
	${info EXECUTABLE CREATED: ${NAME_SERVER}}

${NAME_CLIENT}: ${OBJS_CLIENT}
	${CC} ${OBJS_CLIENT} -o ${NAME_CLIENT}
	${info EXECUTABLE CREATED: ${NAME_CLIENT}}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} -c -o $@ $<
	${info OBJECT CREATED: $@}

clean:
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT}
	${info REMOVED OBJECTS: ${OBJS_SERVER} ${OBJS_CLIENT}}

fclean: clean
	${RM} ${NAME_SERVER} ${NAME_CLIENT}
	${info REMOVED EXECUTABLES: ${NAME_SERVER} ${NAME_CLIENT}}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: clean fclean re
.SILENT: ${OBJS_SERVER} ${OBJS_CLIENT} ${NAME_SERVER} ${NAME_CLIENT} clean fclean re