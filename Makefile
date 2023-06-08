# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/06/08 15:24:56 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite
# $(info $(ADDHEADERLOC))


# -I Flag adds path where header files are searched during preprocessing
SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror -I. -I$(BASEPATHSRC) -I$(BASEPATHTEST)
ADDHEADERLOC = $(patsubst %,-I%,$(HEADERPATH))
NAME = libftprintf.a
NAMELIBFT = libft.a
TARGET_EXTENSION=out
LINK= cc
CC = cc

PATHPROJABS = /home/smatthes/42cursus/projects42/printf/
SUBFOLDERSRC = .
BASEPATHSRC = ./src/
PATHSRC = $(patsubst %,$(BASEPATHSRC)%,$(SUBFOLDERSRC))
PATHBUILD = build/
PATHOBJ = build/obj/
PATHTESTEXE = build/exe/
PATHRES = build/results/
PATHUNITY = ./libft/unity/src/
PATHLIBFT = libft/
BASEPATHTEST = ./srctest/
SUBFOLDERTEST = . get_output/ read_output/ utils/
PATHTEST = $(patsubst %,$(BASEPATHTEST)%,$(SUBFOLDERTEST))
HEADERPATH = $(PATHLIBFT)src/ $(PATHUNITY) $(BASEPATHTEST)


VPATH = $(PATHSRC) $(PATHTEST) $(PATHUNITY)

SRC = test.c

SRCTEST = 	test_test.c \
			test_read.c \
			test_controller.c \
			test_all.c \
			test_comb.c \
			test_single_c.c \
			test_single_d.c \
			test_single_gen.c \
			test_single_i.c \
			test_single_p.c \
			test_single_s.c \
			test_single_u.c \
			test_single_x.c \
			test_single_X.c \
			file_handling.c 

OBJFNAME = $(SRC:.c=.o)
OBJ = $(patsubst %,$(PATHOBJ)%,$(OBJFNAME))

OBJTESTFNAME = $(SRCTEST:.c=.o)
OBJTEST = $(patsubst %,$(PATHOBJ)%,$(OBJTESTFNAME))

TESTWRITERESULT = $(PATHRES)test_results.txt
TESTWRITEEXENAME = test_results.$(TARGET_EXTENSION)
TESTWRITEEXE = $(PATHTESTEXE)$(TESTWRITEEXENAME)

PASS = `grep -s PASS $(PATHRES)*.txt`
PASSNUM = `grep -s -c PASS $(PATHRES)*.txt`
FAIL = `grep -s FAIL $(PATHRES)*.txt`
FAILNUM = `grep -s -c FAIL $(PATHRES)*.txt`
IGNORE = `grep -s IGNORE $(PATHRES)*.txt`
IGNORENUM = `grep -s -c IGNORE $(PATHRES)*.txt`

.PHONY: all clean fclean re bonus test testunit print testwrite

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

# create object files from source files
# any path in VPATH is searched for source files
$(PATHOBJ)%.o: %.c
	$(CC) $(CFLAGS) $(ADDHEADERLOC) -c $< -o $@

# grab results from results files
test:: testclean libft testresults
	$(call color_print_heading,$(YELLOW),IGNORES,$(IGNORENUM))
	@echo "$(IGNORE)"
	$(call color_print_heading,$(RED),FAILURES,$(FAILNUM))
	@echo "$(FAIL)"
	$(call color_print_heading,$(GREEN),PASSED,$(PASSNUM))
	@echo "$(PASS)"
	@printf "\nDONE\n"

libft::
	make -C libft
	cp $(PATHLIBFT)$(NAMELIBFT) $(NAME)

testresults: $(TESTWRITEEXE)
	@-printf "\n";\
	cd $(PATHPROJABS)$(PATHTESTEXE);\
	./$(TESTWRITEEXENAME)

$(TESTWRITEEXE):: $(OBJTEST)
	$(LINK) -o $@ $^ -L. $(NAME)

clean: testclean
	$(RM) $(OBJ)

testclean:
	$(RM) $(OBJTEST)
	$(RM) $(RESULTS)
	$(RM) $(TESTWRITEEXE)
	$(RM) $(TESTWRITERESULT)
	$(RM) $(PATHOBJ)unity.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

# tells makefile not to delete the following files after running
.PRECIOUS: $(TESTWRITEEXE)
.PRECIOUS: $(PATHOBJ)%.o
.PRECIOUS: $(PATHRES)%.txt

BLACK=0
RED=1
GREEN=2
YELLOW=3
BLUE=4
MAGENTA=5
CYAN=6
WHITE=7

define color_print_heading
    @tput setaf $1
	@printf "\n"
	@printf "%-20s%-s%-s%-20s" "************" $2 "($3)" "************"
	@printf "\n\n"
    @tput sgr0
endef
