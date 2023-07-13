# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:24:59 by tchoquet          #+#    #+#              #
#    Updated: 2023/07/13 18:41:18 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT				= .
SRCS_DIR			= ${ROOT}/sources
FT_PRINTF_SRC_DIR	= ${SRCS_DIR}/ft_printf_utils
INCLUDES_DIR 		= ${ROOT}/includes
BUILD_DIR			= ${ROOT}/.build

SRC	= ${wildcard ${SRCS_DIR}/*.c} ${wildcard ${FT_PRINTF_SRC_DIR}/*.c}
OBJ = ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${patsubst ${FT_PRINTF_SRC_DIR}%, ${BUILD_DIR}%, ${SRC:.c=.o}}}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME			= ${ROOT}/libft.a
EXPORT_INCLUDE	= ${ROOT}/libft.h

vpath %.c ${ROOT} ${SRCS_DIR} ${FT_PRINTF_SRC_DIR}

.PHONY: all clean fclean


all: ${NAME} ${EXPORT_INCLUDE}

${NAME}: ${OBJ}
	@ar rc $@ $^
	@echo "Archive created at $@."

clean:
	@rm -rf ${OBJ}
	@echo "Object files in ${BUILD_DIR} deleted."

fclean:
	@rm -rf ${NAME}
	@echo "${NAME} deleted."
	@rm -rf ${EXPORT_INCLUDE}
	@echo "${EXPORT_INCLUDE} deleted."


#All targets
${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}

${ROOT}/%.h: ${INCLUDES_DIR}/%.h | ${EXPORT_INCLUDE_DIR}
	@cp $< $@
	@echo "Include file copied at $@."


#folders
${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created."

