# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:19:15 by jibot             #+#    #+#              #
#    Updated: 2022/04/04 14:04:20 by jibot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc -Wall -Wextra -Werror

RM		= rm -f

SRCS	= Alg_exec.c Alg_ops.c Calcs.c Parsing.c Stack_ops.c Stack_utils.c Utils.c Errors.c main.c

OBJS	= ${SRCS:.c=.o}

all:		${NAME}

%.o:	%.c
			${CC} -c $< -o $@

${NAME}:	${OBJS} 
			make all -C ./libft
			${CC} -o ${NAME} ${OBJS} libft/libft.a
			
clean: 
			${RM} ${SRCS:.c=.o}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus_re:	fclean bonus

.PHONY:		all clean fclean re
