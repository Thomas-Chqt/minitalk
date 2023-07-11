# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 17:54:51 by tchoquet          #+#    #+#              #
#    Updated: 2023/07/11 18:48:55 by tchoquet         ###   ########.fr        #
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

CLIENT_SRC			= ${wildcard ${CLIENT_SRCS_DIR}/*.c}
CLIENT_OBJ			= ${patsubst ${CLIENT_SRCS_DIR}%, ${CLIENT_BUILD_DIR}%, ${CLIENT_SRC:.c=.o}}
CLIENT_OBJ_DEBUG	= ${CLIENT_OBJ:.o=_debug.o}

SERVER_SRC			= ${wildcard ${SERVER_SRCS_DIR}/*.c}
SERVER_OBJ			= ${patsubst ${SERVER_SRCS_DIR}%, ${SERVER_BUILD_DIR}%, ${SERVER_SRC:.c=.o}}
SERVER_OBJ_DEBUG	= ${SERVER_OBJ:.o=_debug.o}

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
debug: CFLAGS		= -g -D MEMCHECK
EXTERNAL_LIBS		= -l ft
EXTERNAL_LIBS_DEBUG	= -l ft_debug -l memory_leak_detector

CLIENT_NAME			= ${ROOT}/client
CLIENT_NAME_DEBUG	= ${ROOT}/client_debug
NAME				= ${CLIENT_NAME} ${SERVER_NAME}

SERVER_NAME			= ${ROOT}/server
SERVER_NAME_DEBUG	= ${ROOT}/server_debug
NAME_DEBUG			= ${CLIENT_NAME_DEBUG} ${SERVER_NAME_DEBUG}


.PHONY: all clean fclean re debug cleandebug fcleandebug redebug norm cleanbuild


all: ${NAME}

${CLIENT_NAME}: ${CLIENT_OBJ}
	@${CC} -o $@ $^ ${EXTERNAL_LIBS}
	@echo "Executable created at : $@."

${SERVER_NAME}: ${SERVER_OBJ}
	@${CC} -o $@ $^ ${EXTERNAL_LIBS}
	@echo "Executable created at : $@."

clean:
	@rm -rf ${CLIENT_OBJ} ${SERVER_OBJ}
	@echo "Release object files deleted in ${CLIENT_BUILD_DIR} and ${SERVER_BUILD_DIR} folders."

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted."

re: fclean all




debug: ${NAME_DEBUG}

${CLIENT_NAME_DEBUG}: ${CLIENT_OBJ_DEBUG}
	@${CC} -o $@ $^ ${EXTERNAL_LIBS_DEBUG}
	@echo "Executable created at : $@."
	
${SERVER_NAME_DEBUG}: ${SERVER_OBJ_DEBUG}
	@${CC} -o $@ $^ ${EXTERNAL_LIBS_DEBUG}
	@echo "Executable created at : $@."

cleandebug:
	@rm -rf ${CLIENT_OBJ_DEBUG} ${SERVER_OBJ_DEBUG}
	@echo "Debug object files deleted in ${CLIENT_BUILD_DIR} and ${SERVER_BUILD_DIR} folders."

fcleandebug: cleandebug
	@rm -rf ${NAME_DEBUG}
	@echo "${NAME_DEBUG} deleted."

redebug: fcleandebug debug




norm:
	@norminette ${CLIENT_SRCS_DIR} ${CLIENT_INCLUDES_DIR} ${SERVER_SRCS_DIR} ${SERVER_INCLUDES_DIR}


cleanbuild:
	@rm -rf ${CLIENT_BUILD_DIR} ${SERVER_BUILD_DIR}
	@echo "Build folders ${CLIENT_BUILD_DIR} and ${SERVER_BUILD_DIR} deleted."



${CLIENT_BUILD_DIR}/%_debug.o ${CLIENT_BUILD_DIR}/%.o: ${CLIENT_SRCS_DIR}/%.c | ${CLIENT_BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${CLIENT_INCLUDES_DIR}
	
${SERVER_BUILD_DIR}/%_debug.o ${SERVER_BUILD_DIR}/%.o: ${SERVER_SRCS_DIR}/%.c | ${SERVER_BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${SERVER_INCLUDES_DIR}


#folders
${CLIENT_BUILD_DIR} ${SERVER_BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created."