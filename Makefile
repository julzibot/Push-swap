# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:19:15 by jibot             #+#    #+#              #
#    Updated: 2022/03/10 17:06:11 by jibot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc -Wall -Wextra -Werror

RM		= rm -f

SRCS	= Push_swap.c main.c ./libft/ft_calloc.c ./libft/ft_split.c ./libft/ft_isdigit.c ./libft/ft_atoi.c

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
