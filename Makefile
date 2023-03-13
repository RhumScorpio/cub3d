# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:41:59 by clesaffr          #+#    #+#              #
#    Updated: 2023/03/10 14:59:52 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = main.c

PATH_OBJS = .objs/

PATH_LIBFT = libft/

LIBFT = libft.a

OBJS = ${SRCS:.c=.o}

F_OBJS = $(addprefix ${PATH_OBJS}, ${OBJS})

F_LIBFT = $(addprefix ${PATH_LIBFT}, ${LIBFT})

all: lib $(PATH_OBJS) $(NAME)

lib:
	make -C $(PATH_LIBFT)

$(PATH_OBJS):	
	mkdir -p $(PATH_OBJS)

${PATH_OBJS}%.o : %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${F_OBJS}
	${CC} ${F_OBJS} ${FLAGS} -o ${NAME} ${F_LIBFT}

re : fclean all

fclean : clean
	make fclean -C $(PATH_LIBFT)
	rm -f ${NAME}

clean :
	rm -rf ${PATH_OBJS}

.PHONY: clean fclean re all
