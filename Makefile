# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 17:54:51 by tchoquet          #+#    #+#              #
#    Updated: 2023/07/18 16:36:16 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT	= .

CLIENT_ROOT			= ${ROOT}/_client
CLIENT_SRCS_DIR		= ${CLIENT_ROOT}/sources
CLIENT_INCLUDES_DIR	= ${CLIENT_ROOT}/includes
CLIENT_BUILD_DIR	= ${CLIENT_ROOT}/.build

SERVER_ROOT			= ${ROOT}/_server
SERVER_SRCS_DIR		= ${SERVER_ROOT}/sources
SERVER_INCLUDES_DIR	= ${SERVER_ROOT}/includes
SERVER_BUILD_DIR	= ${SERVER_ROOT}/.build

LIBFT_DIR			= ${ROOT}/Libft
LIBFT				= ${LIBFT_DIR}/Libft.a

CLIENT_SRC			= ${wildcard ${CLIENT_SRCS_DIR}/*.c}
CLIENT_OBJ			= ${patsubst ${CLIENT_SRCS_DIR}%, ${CLIENT_BUILD_DIR}%, ${CLIENT_SRC:.c=.o}}

SERVER_SRC			= ${wildcard ${SERVER_SRCS_DIR}/*.c}
SERVER_OBJ			= ${patsubst ${SERVER_SRCS_DIR}%, ${SERVER_BUILD_DIR}%, ${SERVER_SRC:.c=.o}}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBS	= ${LIBFT}

CLIENT_NAME			= ${ROOT}/client
SERVER_NAME			= ${ROOT}/server
NAME				= ${CLIENT_NAME} ${SERVER_NAME}


.PHONY: all clean fclean re


all: ${NAME}

${CLIENT_NAME}: ${LIBS} ${CLIENT_OBJ}
	@${CC} -o $@ $^
	@echo "Executable created at : $@."

${SERVER_NAME}: ${LIBS} ${SERVER_OBJ}
	@${CC} -o $@ $^
	@echo "Executable created at : $@."

clean:
	@make -C ${LIBFT_DIR} clean
	@rm -rf ${CLIENT_BUILD_DIR} ${SERVER_BUILD_DIR}
	@echo "${CLIENT_BUILD_DIR} and ${SERVER_BUILD_DIR} folders deleted."

fclean: clean
	make -C ${LIBFT_DIR} fclean
	@rm -rf ${NAME}
	@echo "${NAME} deleted."

re: fclean all


${CLIENT_BUILD_DIR}/%_debug.o ${CLIENT_BUILD_DIR}/%.o: ${CLIENT_SRCS_DIR}/%.c | ${CLIENT_BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${CLIENT_INCLUDES_DIR}
	
${SERVER_BUILD_DIR}/%_debug.o ${SERVER_BUILD_DIR}/%.o: ${SERVER_SRCS_DIR}/%.c | ${SERVER_BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${SERVER_INCLUDES_DIR}

${LIBFT}:
	@make -C ${LIBFT_DIR} all


#folders
${CLIENT_BUILD_DIR} ${SERVER_BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created."