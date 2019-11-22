# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 15:25:40 by avaldes-          #+#    #+#              #
#    Updated: 2019/09/22 22:08:00 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rush-02
CFLAGS		= -Wextra -Wall -Werror
MAIN		= src/main.c
LIB			= src/functions/ft_checkerror.c src/functions/convert_to_word.c src/functions/ft_atoi.c src/functions/ft_calc_range.c src/functions/ft_clean_newline.c src/functions/ft_compare.c src/functions/ft_countwords.c src/functions/ft_extract_longnumber.c src/functions/ft_extract_words.c src/functions/ft_isalpha.c src/functions/ft_isnbr.c src/functions/ft_isprint.c src/functions/ft_isspace.c src/functions/ft_order_size.c src/functions/ft_putchar.c src/functions/ft_putstr.c src/functions/ft_sort.c src/functions/ft_split.c src/functions/ft_strcatc.c src/functions/ft_strcmp.c src/functions/ft_strcpy.c src/functions/ft_strlen.c src/functions/ft_strncpy.c src/functions/ft_strstr.c src/functions/ft_strstr_tunned.c src/functions/reserve_memorynbr.c src/functions/reserve_memorynbrstr.c src/functions/set_nbr.c src/functions/set_nbrstr.c src/functions/tree.c src/functions/tree2.c src/functions/tree3.c src/functions/tree4.c src/lib/dict.c src/lib/error.c
OBJS		= ${MAIN:.c=.o} ${LIB:.c=.o}
CC			= cc
RM			= rm -f
EXEC		= -o ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${MAIN} ${LIB} ${EXEC}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			clean all

.PHONY:	all clean fclean re
