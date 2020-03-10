# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:43:53 by aborboll          #+#    #+#              #
#    Updated: 2020/03/02 18:54:44 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				=	libft.a
OUTPUT				=	LIBFT

CC					=	@gcc
SH					=	@bash
RM					=	@/bin/rm -rf
FLAGS				=	-Wextra -Wall -Werror -g

HEADER				=	includes
OBJ_DIR				=	obj/
SRC_DIR				=	srcs
RESULT				=	$(shell cat output.txt)
AUTHOR				=	$(shell cat author)
LAST_COMMIT_DATE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%ad   [%cr]")
LAST_COMMIT_HASH	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%H")
LAST_COMMIT_MESSAGE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%s")

STR					= 	ft_strcat.c				ft_strncat.c			ft_strstr.c				ft_strchr.c				\
						ft_strlcat.c			ft_strlcpy.c			ft_strcpy.c				ft_strlen.c				\
						ft_strdup.c				ft_strncpy.c			ft_strjoin.c			ft_strnew.c				\
						ft_strrev.c				ft_countwords.c			ft_strmapi.c			ft_strncmp.c			\
						ft_strcmp.c				ft_strnstr.c			ft_split.c				ft_strrchr.c			\
						ft_strtrim.c			ft_substr.c				ft_tolower.c			ft_toupper.c			\
						ft_strjoin_free.c		ft_strto.c				ft_strhas.c

UTILS				=	ft_isalnum.c			ft_isalpha.c			ft_isascii.c			ft_isdigit.c			\
						ft_isspace.c			ft_isprint.c			ft_numlen.c

MEM					=	ft_memccpy.c			ft_memchr.c				ft_memcmp.c				ft_memcpy.c				\
						ft_memmove.c			ft_memset.c				ft_bzero.c				ft_calloc.c				\
						ft_strdel.c

CONVERT				=	ft_atoi.c				ft_itoa.c				ft_itoa_long.c			ft_itoa_llong.c			\
						ft_itoa_ullong.c		ft_utoabase.c			ft_abs.c

BONUS				=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	ft_lstsize_bonus.c		ft_lstlast_bonus.c		\
						ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c		\
						ft_lstmap_bonus.c

FT_PRINTF			=	ft_printf/ft_printf.c	ft_printf/struct.c		ft_printf/check.c		ft_printf/do.c			\
						ft_printf/do_numbers.c	ft_printf/debug.c		ft_printf/is.c			ft_printf/do_strings.c	\
						ft_printf/do_address.c	ft_printf/do_hexadecimal.c	ft_printf/do_octal.c	ft_printf/misc.c

SOURCES				=	$(STR) $(UTILS) $(MEM) $(CONVERT) $(BONUS) $(FT_PRINTF)

NORME				=	$(addsuffix /*.h,$(HEADER)) \
						$(addprefix $(SRC_DIR)/,$(SOURCES))

#	Objects
OFILE				=			$(SOURCES:%.c=%.o)
OBJ					=			$(addprefix $(OBJ_DIR), $(OFILE))

# Functions
disp_indent			=	for I in `seq 1 $(MAKELEVEL)`; do \
						test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
						done

exec_color			=	$(call disp_indent); \
						echo $(1)$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)"\033[31m"; \
						$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)

disp_title			=	$(call disp_indent); \
						echo "\033[38;5;$(2);m[  $(1) \#$(MAKELEVEL)  ]\033[0m"


################
##   COLORS   ##
################

Y					=	$(shell printf "\033[33m")
R					=	$(shell printf "\033[31m")
G					=	$(shell printf "\033[32m")
CYAN				=	$(shell printf "\033[36m")
B					=	$(shell printf "\033[34m")
X					=	$(shell printf "\033[0m")
UP					=	$(shell printf "\033[A")
CUT					=	$(shell printf "\033[K")
W					=	$(shell printf "\033[37m")
UND					=	$(shell printf "\033[4m")
BLINK				=	$(shell printf "\033[5m")
BOLD				=	$(shell printf "\033[1m")
UP					=	$(shell printf "\033[5A")

NORM_COLOR			=	153
NORM_COLOR_T		=	141
NORM_COLOR_ERR		=	160
NORM_COLOR_WAR		=	214

#	Make all files.
all:		$(NAME)

#	Objects directory
$(OBJ_DIR):
			@echo ${B}Creating: ${R}$(OBJ_DIR)${X}
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/ft_printf

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
			$(CC) -o $(OBJ_DIR)$@ -I $(HEADER) -c $(SRC_DIR)/$(@:%.o=%.c) $(FLAGS)


clean:		##@Cleaning Clean all objects.
			$(RM) $(OBJ_DIR)

normi:		##@Checks Check norminette.
			@$(call disp_title,Checking norminette,$(NORM_COLOR_T))
			@norminette $(NORME) | sed "s/Norme/[0;1;$(NORM_COLOR_T)m➤  [0;38;5;$(NORM_COLOR)mNorme/g;s/Warning/[38;5;$(NORM_COLOR_WAR)mWarning/g;s/Error/[38;5;$(NORM_COLOR_ERR)mError/g"


test:		##@Checks Run pft_2019 test.
			@echo
			@sleep 3
			@make re -C $(TESTER_DIR)
			@make test -C $(TESTER_DIR)

run:		##@Compilation Run main.c script & check leaks.
			@echo ${B}Creating: ${R}$(OUTPUT)${X}
			@$(CC) $(FLAGS) main.c -g $(NAME) -I $(HEADER) -o $(OUTPUT)
			@./$(OUTPUT)

HELP_SCRIPT = \
			while(<>) { push @{$$help{$$2 // 'options'}}, [$$1, $$3] if /^([a-zA-Z\-\%_]+)\s*:.*\#\#(?:@([a-zA-Z\-\%]+))?\s(.*)$$/ }; \
			for (sort keys %help) { \
				print " ${R}$$_:${RESET}\n"; \
				for (@{$$help{$$_}}) { \
					$$sep = " " x (32 - length $$_->[0]); \
					print "    ${CYAN}$$_->[0]${R}$$sep${B}$$_->[1]${X}\n"; \
				}; \
				print "\n"; \
			}

bonus:		##@Compilation Compilation Make all bonus files.
			@make

fclean:		##@Cleaning Remove all objects and executables.
			$(RM) $(OUTPUT)
			$(RM) $(OBJ_DIR)
			$(RM) $(NAME)
			@echo ${CUT}${B}${OUTPUT}  :${X} [Garbage collector:${Y} ${OUTPUT} $(NAME) *.o${X}][${G}OK!${X}]


help:		##@Help View all available commands.
			$(shell $(TARGETS_EXE))
			@echo ${CYAN} Proyecto: ${UND}${BOLD}$(OUTPUT)${CYAN}${X}${CYAN}${UND}\\t\\t\\t\\t\\tAuthor: $(AUTHOR)${X}
			@echo ${CYAN} Last commit:${X}
			@echo ${CYAN} \\tDate: $(LAST_COMMIT_DATE)
			@echo ${CYAN} \\tHash: $(LAST_COMMIT_HASH)${X}
			@echo ${CYAN} \\tMessage: $(LAST_COMMIT_MESSAGE)${X}
			@echo ${CYAN}--------------------------------------------------------------------------
			@echo ${CYAN} Available commands:
			@perl -e '$(HELP_SCRIPT)' $(MAKEFILE_LIST)
			@echo ${CYAN}--------------------------------------------------------------------------

re:			##@Compilation Call fclean => all
			@make fclean
			@make all

.PHONY:		all clean flclean re

