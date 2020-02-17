OUTPUT				=	FT_SERVER

DOCKER				=	docker
SH					=	@bash
RM					=	@/bin/rm -rf


RESULT				=	$(shell cat output.txt)
AUTHOR				=	$(shell cat author)
LAST_COMMIT_DATE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%ad   [%cr]")
LAST_COMMIT_HASH	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%H")
LAST_COMMIT_MESSAGE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%s")

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

all:		##@Build Build all files
			@make build

build:		##@Build Build docker image
			@$(DOCKER) image build -t $(shell echo $(OUTPUT) | tr A-Z a-z) .

run:		##@Misc Run docker image
			@echo ${B}Running: ${R}$(OUTPUT)${X}
			@docker container prune --force
			$(DOCKER) run -it -p 80:80 -p 443:443 $(shell echo $(OUTPUT) | tr A-Z a-z)

clean:		##@Misc Clean docker image
			docker image prune -a -f && docker volume prune -f && docker system prune -f

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

re:			##@Misc Call clean => all
			@make clean
			@make all

.PHONY:		all build clean re
