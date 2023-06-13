# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 15:26:55 by jodufour          #+#    #+#              #
#    Updated: 2023/06/14 00:47:33 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	cc
LINK				=	cc
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
MLX_INC_DIR			=	.
MLX_INC_DIR			:=	${MLX_DIR}/${MLX_INC_DIR}

#######################################
#              LIBRARIES              #
#######################################
FT_IO				=	libft_io
FT_IO_A				=	${FT_IO_DIR}/${FT_IO}.a

FT_STRING			=	libft_string
FT_STRING_A			=	${FT_STRING_DIR}/${FT_STRING}.a

MLX					=	libmlx
MLX_A				=	${MLX_DIR}/${MLX}.a

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					${addprefix direction/,					\
						${addprefix list/,					\
							direction_list_add_after.c		\
							direction_list_add_back.c		\
							direction_list_add_before.c		\
							direction_list_add_front.c		\
							direction_list_clear.c			\
							direction_list_del_one.c		\
							direction_list_init.c			\
							direction_list_print.c			\
							direction_list_push_after.c		\
							direction_list_push_back.c		\
							direction_list_push_before.c	\
							direction_list_push_front.c		\
						}									\
						${addprefix node/,					\
							direction_node_new.c			\
						}									\
					}										\
					${addprefix event/,						\
						event_none.c						\
						event_quit.c						\
					}										\
					${addprefix game/,						\
						game_destroy.c						\
						game_display.c						\
						game_init.c							\
					}										\
					${addprefix hook/,						\
						hook_key_press.c					\
						hook_key_release.c					\
						hook_setup.c						\
					}										\
					${addprefix image/,						\
						image_destroy.c						\
						image_fill_square.c					\
						image_init.c						\
					}										\
					${addprefix map/,						\
						map_destroy.c						\
						map_init.c							\
					}										\
					${addprefix player/,					\
						player_destroy.c					\
						player_init.c						\
						player_print.c						\
					}										\
					${addprefix window/,					\
						window_destroy.c					\
						window_init.c						\
					}										\
					main.c

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
LDFLAGS			+=	-L${MLX_DIR} -l${patsubst lib%,%,${MLX}}
LDFLAGS			+=	-lX11
LDFLAGS			+=	-lXext
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
	${MAKE} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}
	${MAKE} clean -C ${MLX_DIR}

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre

-include coffee.mk
-include norm.mk
