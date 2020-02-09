# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:43:53 by aborboll          #+#    #+#              #
#    Updated: 2020/02/08 17:40:44 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libft.a

CC			=	@gcc
RM			=	@/bin/rm -rf
CFLAGS		=	-Wextra -Wall -Werror -g

INC_DIR		=	includes
OBJ_DIR		=	obj/
SRC_DIR		=	srcs/

CFIND =     	$(CFILE:%=$(SRC_DIR)%)

STR			= 	ft_strcat.c				ft_strncat.c			ft_strstr.c				ft_strchr.c			\
				ft_strlcat.c			ft_strlcpy.c			ft_strcpy.c				ft_strlen.c			\
				ft_strdup.c				ft_strncpy.c			ft_strjoin.c			ft_strnew.c			\
				ft_strrev.c				ft_countwords.c			ft_strmapi.c			ft_strncmp.c		\
				ft_strcmp.c				ft_strnstr.c			ft_split.c				ft_strrchr.c		\
				ft_strtrim.c			ft_substr.c				ft_tolower.c			ft_toupper.c		\
				ft_strjoin_free.c		ft_strto.c				ft_strhas.c

UTILS		=	ft_isalnum.c			ft_isalpha.c			ft_isascii.c			ft_isdigit.c		\
				ft_isspace.c			ft_isprint.c			ft_numlen.c

FT_PRINTF	= 	ft_putchar_fd.c			ft_putchar.c			ft_putendl_fd.c			ft_putendl.c		\
				ft_putnbr_fd.c			ft_putnbr.c				ft_putstr_fd.c			ft_putstr.c			\
				ft_get_next_line.c

MEM			=	ft_memccpy.c			ft_memchr.c				ft_memcmp.c				ft_memcpy.c			\
				ft_memmove.c			ft_memset.c				ft_bzero.c				ft_calloc.c			\
				ft_strdel.c

CONVERT		=	ft_atoi.c				ft_itoa.c				ft_itoa_long.c			ft_itoa_llong.c	\
				ft_itoa_ullong.c		ft_utoabase.c			ft_abs.c

BONUS		=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	ft_lstsize_bonus.c		ft_lstlast_bonus.c	\
				ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c	\
				ft_lstmap_bonus.c

#	Objects
LIBS		=	$(STR) $(UTILS) $(FT_PRINTF) $(MEM) $(CONVERT) $(BONUS)
OFILE =			$(LIBS:%.c=%.o)
OBJ =			$(addprefix $(OBJ_DIR), $(OFILE))

################
##   COLORS   ##
################

Y				=	"\033[33m"
R				=	"\033[31m"
G				=	"\033[32m"
B				=	"\033[34m"
X				=	"\033[0m"
UP				=	"\033[A"
CUT				=	"\033[K"
UND				=	"\033[4m"
BLINK			=	"\033[5m"
BOLD			=	"\033[1m"
UP				=	"\033[5A"

NORM_COLOR		=	153
NORM_COLOR_T	=	141
NORM_COLOR_ERR	=	160
NORM_COLOR_WAR	=	214

#	First target
all:		$(NAME)


#	Objects directory
$(OBJ_DIR):
			@echo ${B}Creating: ${R}$(OBJ_DIR)${X}
			@mkdir -p $(OBJ_DIR)

#	Normal objects
$(NAME): $(OBJ_DIR) $(OBJ)
			@echo ${R}Compiling libft...${X}
			@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
			@ranlib $(NAME)
			@echo ${B}[----------------]${X}
			@echo ${B}[-- ${BOLD}OK${X}${B} - ${BOLD}LIBFT${X}${B} --]${X}
			@echo ${B}[----------------]${X}


$(OBJ): $(CFIND)
			@printf ${B}'Compiling: '${X}
			@$(MAKE) $(OFILE)

$(OFILE):
			@printf ${R}'$(@:%.o=%.c) '${X}
			$(CC) -o $(OBJ_DIR)$@ -I $(INC_DIR) -c $(SRC_DIR)$(@:%.o=%.c) $(CFLAGS)

#	Removing objects
clean:
			@echo ${CUT}${B}LIBFT :${X} [Garbage collector:${Y} *.o${X}][${G}OK!${X}]
			$(RM) $(OFILE)

#	Removing objects and exe
fclean:
			$(RM) $(OBJ)
			$(RM) $(NAME)
			@echo ${CUT}${B}LIBFT  :${X} [Garbage collector:${Y}  $(NAME) *.o${X}][${G}OK!${X}]

#	All removing then compiling
re: 		fclean all

.PHONY:		all clean flcean re
