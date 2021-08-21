# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 17:38:02 by iwillens          #+#    #+#              #
#    Updated: 2021/08/21 19:17:21 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = clang
CCFLAGS = -Wall -Werror -Wextra 

SRC_DIR = ./srcs
OBJ_DIR = ./build
INC_DIR = ./includes

COMMON_FILES =	${SRC_DIR}/libft_basics.c \
				${SRC_DIR}/libft_atoi.c \
				${SRC_DIR}/arguments.c \
				${SRC_DIR}/arguments_helpers.c \
				${SRC_DIR}/exit.c \
				${SRC_DIR}/oper_push.c \
				${SRC_DIR}/oper_rotate.c \
				${SRC_DIR}/oper_swap.c \
				${SRC_DIR}/oper_reverse.c \
				${SRC_DIR}/oper_helpers.c \
				${SRC_DIR}/sort_small.c \
				${SRC_DIR}/sort_radix.c \
				${SRC_DIR}/push_init.c

PS_SRCS = ${COMMON_FILES} \
		${SRC_DIR}/push_swap.c

CK_SRCS = ${COMMON_FILES} \
		${SRC_DIR}/bonus_checker.c \
		${SRC_DIR}/bonus_checker_ops.c \
		${SRC_DIR}/bonus_checker_validate.c \
		${SRC_DIR}/bonus_checker_gnl.c

PS_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${PS_SRCS})
CK_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${CK_SRCS})

all: ${NAME}

${NAME}: ${PS_OBJS} ${INC_DIR}
	${CC} ${CCFLAGS} ${PS_OBJS} -I ${INC_DIR} -o ${NAME}

bonus: ${BONUS}

${BONUS}: ${CK_OBJS} ${INC_DIR}
	${CC} ${CCFLAGS} ${CK_OBJS} -I ${INC_DIR} -o ${BONUS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_DIR}
	mkdir -p ${OBJ_DIR}
	${CC} -c ${CCFLAGS} $< -I ${INC_DIR} -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ./${NAME}
	rm -rf ./checker

re: fclean all
