# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:43:53 by aborboll          #+#    #+#              #
#    Updated: 2019/11/16 18:59:38 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libft.a
CC			=	gcc
RM			=	@/bin/rm -f
CFLAGS		=	-Wextra -Wall -Werror
AR			=	ar
ARFLAGS		=	rc

STR			= 	ft_strcat.c				ft_strncat.c			ft_strstr.c				ft_strchr.c			\
				ft_strlcat.c			ft_strlcpy.c			ft_strcpy.c				ft_strlen.c			\
				ft_strdup.c				ft_strncpy.c			ft_strjoin.c			ft_strnew.c			\
				ft_strrev.c				ft_countwords.c			ft_strmapi.c			ft_strncmp.c		\
				ft_strcmp.c				ft_strnstr.c			ft_split.c				ft_strrchr.c		\
				ft_strtrim.c			ft_substr.c				ft_tolower.c			ft_toupper.c

UTILS		=	ft_isalnum.c			ft_isalpha.c			ft_isascii.c			ft_isdigit.c		\
				ft_isspace.c			ft_isprint.c			ft_numlen.c

FT_PRINTF	= 	ft_putchar_fd.c			ft_putchar.c			ft_putendl_fd.c			ft_putendl.c		\
				ft_putnbr_fd.c			ft_putnbr.c				ft_putstr_fd.c			ft_putstr.c

MEM			=	ft_memccpy.c			ft_memchr.c				ft_memcmp.c				ft_memcpy.c			\
				ft_memmove.c			ft_memset.c				ft_bzero.c				ft_calloc.c			\

CONVERT		=	ft_atoi.c				ft_itoa.c

BONUS		=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	ft_lstsize_bonus.c		ft_lstlast_bonus.c	\
				ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c	\
				ft_lstmap_bonus.c

#	Objects
LIBS		=	$(STR) $(UTILS) $(FT_PRINTF) $(MEM) $(CONVERT)
OBJS		=	$(LIBS:.c=.o)
OBJS_BONUS	=	$(BONUS:%.c=%.o)

################
##   COLORS   ##
################

Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"

#################
##  TARGETS    ##
#################

#	First target
all:		$(NAME)

#	Normal objects
$(NAME):	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			ranlib $(NAME)

#	Bonus objects
bonus:		$(OBJS) $(OBJS_BONUS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)
			ranlib $(NAME)

#	Removing objects
clean:
			@echo ${B}Cleaning ${X}${R}${OBJS}${OBJS_BONUS}${X}
			$(RM) $(OBJS) $(OBJS_BONUS)

#	Removing objects and exe
fclean:		clean
			@echo ${B}Cleaning ${X}${R}${NAME}${X}
			$(RM) $(NAME)

#	All removing then compiling
re:			fclean all

%.o: %.c
			$(CC) -o $@ -c $< $(CFLAGS)

.PHONY:		all clean fclean re
