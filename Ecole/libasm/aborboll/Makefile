# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 15:33:18 by aborboll          #+#    #+#              #
#    Updated: 2021/02/09 19:16:54 by aborboll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libasm.a
OUTPUT				=	libasm

CC					=	@gcc
NA					=	@nasm
SH					=	@bash
RM					=	@/bin/rm -rf
FLAGS				=	-Wextra -Wall

HEADER_DIR			=	includes/
OBJ_DIR				=	obj/
SRC_DIR				=	srcs/
TESTER_DIR			=	42libasm_tester/

RESULT				=	$(shell cat output.txt)
AUTHOR				=	$(shell cat author)
LAST_COMMIT_DATE	=	$(shell git log -1 --date=format:"%m/%d/%Y" --format="%ad   [%cr]")
LAST_COMMIT_HASH	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%H")
LAST_COMMIT_MESSAGE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format=\'%s\')
OS					=	$(shell lsb_release -si)
USER				=	$(shell whoami)
ARCH				=	$(shell uname -m | sed 's/x86_//;s/i[3-6]86/32/')
VER					=	$(shell lsb_release -sr)

# Mandatory part

STR					=	ft_strlen.s	ft_strcmp.s	ft_strcpy.s	ft_strdup.s
UTILS				=	ft_read.s	ft_write.s

SOURCES				=	$(STR) $(UTILS)

NORME				=	$(addsuffix *.h,$(HEADER_DIR)) \
						$(addprefix $(SRC_DIR),$(SRCS))


# Mandatory Objects
OFILE				=	$(SOURCES:%.s=%.o)
OBJS				=	$(addprefix $(OBJ_DIR), $(OFILE))

# Functions
disp_indent			=	for I in `seq 1 $(MAKELEVEL)`; do \
						test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
						done

exec_color			=	$(call disp_indent); \
						echo $(1)$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)"\033[31m"; \
						$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)

disp_title			=	$(call disp_indent); \
						echo "$(2)[  $(1) \#$(MAKELEVEL)  ]\033[0m"


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
NORM_COLOR_T		=	$(shell printf "\033[0;1;141m")
NORM_COLOR			=	$(shell printf "\033[0;38;5;153m")
NORM_COLOR_WAR		=	$(shell printf "\033[38;5;214m")
NORM_COLOR_ERR		=	$(shell printf "\033[0;41m")
BG_X				=	$(shell printf "\033[0;39m")

# Make all files.
all:
			@make $(NAME)
			
# Objects directory
$(OBJ_DIR):
			@echo ${CUT}[${Y}$(OUTPUT)]${X} ${B}Creating: ${R}$(OBJ_DIR)${X}
			@mkdir -p $(OBJ_DIR)

# Normal objects
$(NAME): $(OBJ_DIR) $(OBJS)
			@echo ${B}[-----------------------]${X}
			@echo ${B}[---- ${BOLD}OK${X}${B} - ${BOLD}$(NAME)${X}${B} ----]${X}
			@echo ${B}[---- 🤞 Good luck 🤞 ----]${X}
			@echo ${B}[-----------------------]${X}
			@ar rcs $(NAME) $(OBJS)

$(OBJS):
			@printf '${CUT}[${Y}$(OUTPUT)]${X} ${B}Compiling: ${X}'
			@make $(OFILE)
			@printf ${B}Crafting: ${R}$(OUTPUT)${X}
			@gcc  main.c $(OBJS) -I $(HEADER_DIR) $(FLAGS) -o $(OUTPUT)
			@echo ${B}Craftinag: ${R}$(OUTPUT)${X}

$(OFILE):
			@printf ${R}'$(@:%.o=%.s) '${X}
			$(NA) -f macho64  $(SRC_DIR)$(@:%.o=%.s) -o $(OBJ_DIR)$(@:%.s=%.o)

##@ Cleaning
clean:		## Clean all objects.
			$(RM) $(OBJ_DIR)


fclean:		## Remove all objects and executables.
			$(RM) $(OUTPUT)
			$(RM) $(OBJ_DIR)
			$(RM) $(NAME)
			@echo ${CUT}[${Y}$(OUTPUT)]${X} [Garbage collector:${Y} ${OUTPUT} $(NAME) *.o${X}][${G}OK!${X}]

##@ Compilation
re:			## Call fclean => all
			@make clean
			@make all

##@ Testing

test:		## Make libasm test
			@make re
			cd $(TESTER_DIR) && ./runtest.sh


##@ Help
help:		## View all available commands.
			$(shell $(TARGETS_EXE))
			@echo ${CYAN} Proyecto: ${UND}${BOLD}$(OUTPUT)${CYAN}${X}${CYAN}${UND}\\t\\t\\t\\t\\tAuthor: $(AUTHOR)${X}
			@echo ${CYAN} Last commit:${X}
			@echo ${CYAN} \\tDate: $(LAST_COMMIT_DATE)
			@echo ${CYAN} \\tHash: $(LAST_COMMIT_HASH)${X}
			@echo ${CYAN} \\tMessage: $(LAST_COMMIT_MESSAGE)${X}
			@echo ${CYAN}--------------------------------------------------------------------------
			@echo ${CYAN}Available commands: "\\t\\t\\t\\t(${G}Usage:${X} make ${CYAN}<target>${X})"
			@awk 'BEGIN {FS = ":.*##"; printf ""} /^[a-zA-Z_-]+:.*?##/ { printf "  ${CYAN}%-25s${X} %s\n", $$1, $$2 } /^##@/ { printf "\n${UND}${BOLD}%s${X}\n", substr($$0, 5) } ' $(MAKEFILE_LIST)
			@echo ${CYAN}--------------------------------------------------------------------------

.PHONY:		all clean flclean re bonus test
