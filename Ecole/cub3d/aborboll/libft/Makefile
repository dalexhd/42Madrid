# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:43:53 by aborboll          #+#    #+#              #
#    Updated: 2020/10/13 18:28:17 by aborboll         ###   ########.fr        #
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
COVID_NORM			=	ruby -e STDOUT.sync=true -e 'load($$0=ARGV.shift)' ~/.norminette/norminette.rb
RESULT				=	$(shell cat output.txt)
AUTHOR				=	$(shell cat author)
LAST_COMMIT_DATE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%ad   [%cr]")
LAST_COMMIT_HASH	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%H")
LAST_COMMIT_MESSAGE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%s")
OS					=	$(shell lsb_release -si)
ARCH				=	$(shell uname -m | sed 's/x86_//;s/i[3-6]86/32/')
VER					=	$(shell lsb_release -sr)

STR					= 	ft_strcat.c				ft_strncat.c			ft_strstr.c				ft_strchr.c				\
						ft_strlcat.c			ft_strlcpy.c			ft_strcpy.c				ft_strlen.c				\
						ft_strdup.c				ft_strncpy.c			ft_strjoin.c			ft_strnew.c				\
						ft_strrev.c				ft_countwords.c			ft_strmapi.c			ft_strncmp.c			\
						ft_strcmp.c				ft_strnstr.c			ft_split.c				ft_strrchr.c			\
						ft_strtrim.c			ft_substr.c				ft_tolower.c			ft_toupper.c			\
						ft_strjoin_free.c		ft_strto.c				ft_putchar.c			ft_putstr.c				\
						ft_strevery.c			ft_putchar_fd.c			ft_strendswith.c		ft_countchars.c			\
						ft_putnbr_fd.c			ft_putstr_fd.c			ft_putendl_fd.c			ft_countnumbers.c

UTILS				=	ft_isalnum.c			ft_isalpha.c			ft_isascii.c			ft_isdigit.c			\
						ft_isspace.c			ft_isprint.c			ft_numlen.c				ft_max.c				\
						ft_min.c

MEM					=	ft_memccpy.c			ft_memchr.c				ft_memcmp.c				ft_memcpy.c				\
						ft_memmove.c			ft_memset.c				ft_bzero.c				ft_calloc.c				\
						ft_strdel.c				ft_split_del.c

CONVERT				=	ft_atoi.c				ft_itoa.c				ft_itoa_long.c			ft_itoa_llong.c			\
						ft_itoa_ullong.c		ft_utoabase.c			ft_abs.c				ft_floor.c				\
						ft_deg_to_rad.c			ft_atoll.c

BONUS				=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	ft_lstsize_bonus.c		ft_lstlast_bonus.c		\
						ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c		\
						ft_lstmap_bonus.c

FT_PRINTF			=	ft_printf/ft_printf.c	ft_printf/struct.c		ft_printf/check.c		ft_printf/do.c			\
						ft_printf/do_numbers.c	ft_printf/debug.c		ft_printf/is.c			ft_printf/do_strings.c	\
						ft_printf/do_address.c	ft_printf/do_hex.c		ft_printf/do_octal.c	ft_printf/misc.c		\
						ft_printf/ft_vprintf.c	ft_printf/ft_vfprintf.c	ft_printf/ft_fprintf.c

FT_ALERT			=	ft_alert/ft_error.c		ft_alert/ft_warn.c

FT_GET_NEXT_LINE	=	ft_get_next_line/get_next_line.c

SOURCES				=	$(STR) $(UTILS) $(MEM) $(CONVERT) $(BONUS) $(FT_PRINTF) $(FT_ALERT) $(FT_GET_NEXT_LINE)

NORME				=	$(addsuffix /*.h,$(HEADER)) \
						$(addprefix $(SRC_DIR)/,$(SOURCES))

#	Objects
OFILE				=	$(SOURCES:%.c=%.o)
OBJ					=	$(addprefix $(OBJ_DIR), $(OFILE))

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
NORM_COLOR_ERR		=	$(shell printf "\033[38;5;160m")

#	Make all files.
all:		$(NAME)

#	Objects directory
$(OBJ_DIR):
			@echo ${CUT}[${CYAN}$(OUTPUT)]${X} ${B}Creating: ${R}$(OBJ_DIR)${X}
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/ft_printf
			@mkdir -p $(OBJ_DIR)/ft_alert
			@mkdir -p $(OBJ_DIR)/ft_get_next_line

#	Normal objects
$(NAME): $(OBJ_DIR) $(OBJ)
			@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
			@ranlib $(NAME)
			@echo ${B}[----------------]${X}
			@echo ${B}[-- ${BOLD}OK${X}${B} - ${BOLD}LIBFT${X}${B} --]${X}
			@echo ${B}[----------------]${X}


$(OBJ): $(CFIND)
			@printf '${CUT}[${CYAN}$(OUTPUT)]${X} ${B}Compiling: ${X}'
			@make $(OFILE)
			@echo

$(OFILE):
			@printf ${R}'$(@:%.o=%.c) '${X}
			$(CC) -o $(OBJ_DIR)$@ -I $(HEADER) -c $(SRC_DIR)/$(@:%.o=%.c) $(FLAGS)

##@ Checks

normi:		## Check norminette.
			@$(call disp_title,Checking norminette,$(NORM_COLOR_T))
			@if [ ${OS} = "Ubuntu" ]; then\
				$(COVID_NORM) $(NORME) | sed "s/Norme/$(NORM_COLOR_T)➤  $(NORM_COLOR)Norme/g;s/Warning/\t $(NORM_COLOR_WAR)Warning/g;s/Error/\t🚨 $(NORM_COLOR_ERR)Error/gm;s/$$/$(X)/g"; \
			else\
				@norminette $(NORME) | sed "s/Norme/$(NORM_COLOR_T)➤  $(NORM_COLOR)Norme/g;s/Warning/\t $(NORM_COLOR_WAR)Warning/g;s/Error/\t🚨 $(NORM_COLOR_ERR)Error/g"; \
			fi
			@echo -n $(X)

test:		## Run pft_2019 test.
			@echo
			@sleep 3
			@make re -C $(TESTER_DIR)
			@make test -C $(TESTER_DIR)

##@ Cleaning
clean:		## Clean all objects.
			$(RM) $(OBJ_DIR)

fclean:		## Remove all objects and executables.
			$(RM) $(OUTPUT)
			$(RM) $(OBJ_DIR)
			$(RM) $(NAME)
			@echo ${CUT}[${CYAN}$(OUTPUT)]${X} [Garbage collector:${Y} ${OUTPUT} $(NAME) *.o${X}][${G}OK!${X}]

##@ Compilation
run:		## Run main.c script & check leaks.
			@echo ${B}Creating: ${R}$(OUTPUT)${X}
			@$(CC) $(FLAGS) main.c -g $(NAME) -I $(HEADER) -o $(OUTPUT)
			@./$(OUTPUT)

bonus:		## Make all bonus files.
			@make

re:			## Call fclean => all
			@make fclean
			@make all

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

.PHONY:		all clean flclean re

