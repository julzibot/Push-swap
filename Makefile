# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:19:15 by jibot             #+#    #+#              #
#    Updated: 2022/03/21 17:42:30 by jibot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc -g -Wall -Wextra -Werror

RM		= rm -f

SRCS	= Alg_exec.c Alg_ops.c Calcs.c Parsing.c Stack_utils.c Stack_ops.c Utils.c main.c ./libft/ft_strdup.c ./libft/ft_strlen.c ./libft/ft_calloc.c ./libft/ft_split.c ./libft/ft_isdigit.c ./libft/ft_atoi.c

all:		${NAME}

${NAME}:	${SRCS} 
			${CC} ${SRCS} -o ${NAME}
			
clean: 
			${RM} ${SRCS:.c=.o}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus_re:	fclean bonus

.PHONY:		all clean fclean re
