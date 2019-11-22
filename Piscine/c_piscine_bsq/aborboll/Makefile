NAME		= BSQ
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
LIB			= $(wildcard *.c src/*.c)
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
