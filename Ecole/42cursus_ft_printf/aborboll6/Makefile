# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:43:53 by aborboll          #+#    #+#              #
#    Updated: 2020/02/10 15:18:34 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				=	libftprintf.a
OUTPUT				=	FT_PRINTF

CC					=	@gcc
SH					=	@bash
RM					=	@/bin/rm -rf
FLAGS				=	-Wextra -Wall -g

HEADER				=	includes
OBJ_DIR				=	obj/
SRC_DIR				=	srcs
LIBFT_DIR			=	libft/
TESTER_DIR			=	tests/tests
TERSTER_EXE			=	tools/pft_2019/test
RESULT				=	$(shell cat output.txt)
AUTHOR				=	$(shell cat author)
LAST_COMMIT_DATE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%ad   [%cr]")
LAST_COMMIT_HASH	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%H")
LAST_COMMIT_MESSAGE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%s")

SOURCES				=	ft_printf.c	struct.c	check.c		do.c do_numbers.c	debug.c		is.c	do_strings.c	do_address.c	do_hexadecimal.c	do_octal.c	misc.c
LEAKS_EXE			=	./tools/leak_tester/memory_leak.sh ${OUTPUT}
LEAKS_FLAGS			=	--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --dsymutil=yes --show-reachable=yes
NORME				=	$(addsuffix /*.h,$(HEADER)) \
						$(addprefix $(SRC_DIR)/,$(SOURCES)) \
						$(addsuffix /**/*.h,$(LIBFT_DIR)) \
						$(addsuffix /**/*.c,$(LIBFT_DIR))

#	Objects
OBJS				=	$(addprefix $(OBJ_DIR)/, $(SOURCES:%.c=%.o))

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

# Objects directory
$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

# Normal objects
$(NAME): $(OBJ_DIR) $(OBJS)
			@make -C $(LIBFT_DIR)
			@cp libft/libft.a ./$(NAME)
			@echo ${R}Compiling libftprintf...${X}
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo ${B}[--------------------------]${X}
			@echo ${B}[---- ${BOLD}OK${X}${B} - ${BOLD}LIBFTPRINTF${X}${B} ----]${X}
			@echo ${B}[--------------------------]${X}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p obj
			@$(CC) $(FLAGS) -g -I $(HEADER) -o $@ -c $<

clean:		##@Cleaning Clean all objects.
			$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT_DIR)

normi:		##@Checks Check norminette.
			@$(call disp_title,Checking norminette,$(NORM_COLOR_T))
			@norminette $(NORME) | sed "s/Norme/[0;1;$(NORM_COLOR_T)m➤  [0;38;5;$(NORM_COLOR)mNorme/g;s/Warning/[38;5;$(NORM_COLOR_WAR)mWarning/g;s/Error/[38;5;$(NORM_COLOR_ERR)mError/g"

leak:		##@Checks Run memory leak test.
			@if [ $(shell $(LEAKS_EXE) && cat tools/leak_tester/valgrind_out | grep "definitely lost:" | cut -d : -f 2 | cut -d b  -f 1 | tr -d " " | tr -d ",") = "0" ]; then\
				echo ${BOLD}${UND}${G}No memory leaks${X};\
			else\
				echo ${BOLD}${UND}${R}Memory leaks detected${X};\
			fi

test:		##@Checks Run pft_2019 test.
			@echo
			@sleep 3
			@make re -C $(TESTER_DIR)
			@make test -C $(TESTER_DIR)

run:		##@Compilation Run main.c script & check leaks.
			@echo ${B}Creating: ${R}$(OUTPUT)${X}
			@$(CC) $(FLAGS) main.c -g $(NAME) -I $(HEADER) -o $(OUTPUT)
			@printf ${B}'Checking-leaks: '${R}
			@make leak
			@echo ${BOLD}🤞 ${B}Good luck 🤞${X}
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
			@echo ${CUT}${B}LIBFTPRINTF  :${X} [Garbage collector:${Y} ${OUTPUT} $(NAME) *.o${X}][${G}OK!${X}]
			@make fclean -C $(LIBFT_DIR)


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
