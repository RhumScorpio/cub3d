# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 15:26:55 by jodufour          #+#    #+#              #
#    Updated: 2023/05/13 00:05:33 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	cc
LINK				=	cc
CMAKE				=	cmake
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	cub3D.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	src
OBJ_DIR				=	obj
PRV_DIR				=	private

FT_IO_DIR			=	libft_io
FT_IO_INC_DIR		=	include
FT_IO_INC_DIR		:=	${FT_IO_DIR}/${FT_IO_INC_DIR}

FT_STRING_DIR		=	libft_string
FT_STRING_INC_DIR	=	include
FT_STRING_INC_DIR	:=	${FT_STRING_DIR}/${FT_STRING_INC_DIR}

MLX_DIR				=	mlx_linux
MLX_INC_DIR			=	include/MLX42
MLX_INC_DIR			:=	${MLX_DIR}/${MLX_INC_DIR}
MLX_BUILD_DIR		=	build
MLX_BUILD_DIR		:=	${MLX_DIR}/${MLX_BUILD_DIR}

#######################################
#              LIBRARIES              #
#######################################
FT_IO				=	libft_io
FT_IO_A				=	${FT_IO_DIR}/${FT_IO}.a

FT_STRING			=	libft_string
FT_STRING_A			=	${FT_STRING_DIR}/${FT_STRING}.a

MLX					=	libmlx42
MLX_A				=	${MLX_BUILD_DIR}/${MLX}.a

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					main.c			\
					mlx_perror.c

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.c=.o}
OBJ				:=	${addprefix ${OBJ_DIR}/,${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS			=	-c
CFLAGS			+=	-Wall -Wextra -Werror
CFLAGS			+=	-MMD -MP
CFLAGS			+=	-I${PRV_DIR}
CFLAGS			+=	-I${FT_IO_INC_DIR}
CFLAGS			+=	-I${FT_STRING_INC_DIR}
CFLAGS			+=	-I${MLX_INC_DIR}

LDFLAGS			=	-L${FT_IO_DIR} -l${patsubst lib%,%,${FT_IO}}
LDFLAGS			+=	-L${FT_STRING_DIR} -l${patsubst lib%,%,${FT_STRING}}
LDFLAGS			+=	-L${MLX_BUILD_DIR} -l${patsubst lib%,%,${MLX}}
LDFLAGS			+=	-lglfw
LDFLAGS			+=	-lm

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ} ${FT_IO_A} ${FT_STRING_A} ${MLX_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKDIR} ${@D}
	${CC} ${CFLAGS} $< ${OUTPUT_OPTION}

${FT_IO_A} ${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D} DEBUG=${DEBUG}

${MLX_A}:
	${CMAKE} -S ${MLX_DIR} -B ${MLX_BUILD_DIR}
	${CMAKE} --build ${MLX_BUILD_DIR}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}
	${CMAKE} --build ${MLX_BUILD_DIR} --target clean

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre

-include coffee.mk
-include norm.mk
