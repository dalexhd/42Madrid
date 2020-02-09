# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:43:53 by aborboll          #+#    #+#              #
#    Updated: 2020/01/26 13:49:31 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libftprintf.a

CC			=	@gcc
SH			=	@bash
RM			=	@/bin/rm -rf
FLAGS		=	-Wextra -Wall -Werror -g -pedantic

HEADER		=	includes
OBJ_DIR		=	obj/
SRC_DIR		=	srcs
LIBFT_DIR	=	libft/
TESTER_DIR	=	tools/pft_2019
TERSTER_EXE	=	tools/pft_2019/test
RESULT		=	$(shell cat output.txt)

SOURCES		=	ft_printf.c	struct.c	check.c		do.c do_numbers.c	debug.c		is.c	do_strings.c	do_address.c	do_hexadecimal.c
OUTPUT		=	GL
LEAKS_EXE	=	./tools/leak_tester/memory_leak.sh
LEAKS_FLAGS	=	--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --dsymutil=yes
NORME		=	$(addsuffix /*.h,$(HEADER)) \
				$(addprefix $(SRC_DIR)/,$(SOURCES)) \
				$(addsuffix /**/*.h,$(LIBFT_DIR)) \
				$(addsuffix /**/*.c,$(LIBFT_DIR))

#	Objects
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SOURCES:%.c=%.o))

# Functions
disp_indent	=	for I in `seq 1 $(MAKELEVEL)`; do \
				test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
				done

exec_color	=	$(call disp_indent); \
				echo $(1)$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)"\033[31m"; \
				$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)

disp_title	=	$(call disp_indent); \
				echo "\033[38;5;$(2);m[  $(1) \#$(MAKELEVEL)  ]\033[0m"


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
			@mkdir -p $(OBJ_DIR)

#	Normal objects
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

#	Removing objects
clean:
			$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT_DIR)

#	Check norme
normi:
			@$(call disp_title,Checking norminette,$(NORM_COLOR_T))
			@norminette $(NORME) | sed "s/Norme/[0;1;$(NORM_COLOR_T)m➤  [0;38;5;$(NORM_COLOR)mNorme/g;s/Warning/[38;5;$(NORM_COLOR_WAR)mWarning/g;s/Error/[38;5;$(NORM_COLOR_ERR)mError/g"

#	Make memory leak test
leak:
			@if [ $(shell $(LEAKS_EXE) && cat tools/leak_tester/valgrind_out | grep "definitely lost:" | cut -d : -f 2 | cut -d b  -f 1 | tr -d " " | tr -d ",") = "0" ]; then\
				echo ${BOLD}${UND}${G}No memory leaks${X};\
			else\
				echo ${BOLD}${UND}${R}Memory leaks detected${X};\
			fi

#	Make test
test:
			@echo
			@echo
			@sleep 3
			@make re -C $(TESTER_DIR)
			./$(TERSTER_EXE)

#	Make run
run:
			@echo ${B}Creating: ${R}$(OUTPUT)${X}
			@$(CC) $(FLAGS) main.c -g $(NAME) -I $(HEADER) -o $(OUTPUT)
			@printf ${B}'Checking-leaks: '${R}
			@make leak
			@echo ${BOLD}🤞 ${B}Good luck 🤞${X}
			@./$(OUTPUT)

bonus:
			@make

#	Removing objects and exe
fclean:
			$(RM) $(OUTPUT)
			$(RM) $(OBJ_DIR)
			$(RM) $(NAME)
			@echo ${CUT}${B}LIBFTPRINTF  :${X} [Garbage collector:${Y} ${OUTPUT} $(NAME) *.o${X}][${G}OK!${X}]
			@make fclean -C $(LIBFT_DIR)

#	All removing then compiling
re: 		fclean all

.PHONY:		all clean flcean re
