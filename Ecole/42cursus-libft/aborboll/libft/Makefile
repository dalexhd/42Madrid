# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:43:53 by aborboll          #+#    #+#              #
#    Updated: 2019/11/10 21:22:54 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a
CFLAGS		= -Wextra -Wall -Werror
AR			= ar
ARFLAGS		= rc
LIB			= ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isspace.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putchar.c \
				ft_putendl_fd.c \
				ft_putendl.c \
				ft_calloc.c \
				ft_putnbr_fd.c \
				ft_putnbr.c \
				ft_putstr_fd.c \
				ft_putstr.c \
				ft_split.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strstr.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strncpy.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strcpy.c \
				ft_strlen.c \
				ft_numlen.c \
				ft_strnew.c \
				ft_strrev.c \
				ft_countwords.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strcmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c
OBJS		= $(LIB:%.c=%.o)
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"
all:	$(NAME)
CC	= gcc
RM	= @/bin/rm -f
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
			@echo ${B}Cleaning ${X}${R}${OBJS}${X}
			$(RM) $(OBJS)
fclean:		clean
			@echo ${B}Cleaning ${X}${R}${NAME}${X}
			$(RM) $(NAME)

re:			fclean all
.PHONY:	all clean fclean re
