# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/05/29 09:42:56 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite

# copy the file and rename it

# compile unity to object files
# call makefile of library
# compile test files to object files
# compile tests with unity and library
# run executable

CFLAGS = -Wall -Wextra -Werror
HEADERLOCS = -I. -I.$(PATHUNITY)
NAME = libftprintf.a
PATHLIBFT = libft/libft.a
 PATHTEST = test/test/
PATHRESULTS = test/results/
PATHBUILD = /
BUILD_PATHS = $(PATHBUILD) $(PATHBUILD) $(PATHRESULTS) 

SRC = test.c

SRCTEST = $(addprefix test_, $(SRC)) 

COMPILE = $(PATHUNITY) test/test/$(SRCTEST) test.c -L. $(NAME) -I. -o testsample

PATHTOGETTESTRES = ./test/test/get_output/
PATHTOREADTESTRES = ./test/test/read_output/
PATHTOGETOTESTUTILS = ./test/test/utils/

SRCGETTESTRES = 	test_all.c \
					test_controller.c \
					test_main.c \
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
			
SRCREADTESTRES = 	test_read.c \

SRCTESTUTILS = file_handling.c

FULLPATH_SRCGETTESTRES = $(patsubst %,$(PATHTOGETTESTRES)%,$(SRCGETTESTRES))
FULLPATH_SRCREADTESTRES = $(patsubst %,$(PATHTOREADTESTRES)%,$(SRCREADTESTRES))
FULLPATH_SRCTESTUTILS = $(patsubst %,$(PATHTOGETOTESTUTILS)%,$(SRCTESTUTILS))

run_tests: all
	clear
	echo "\n\n"
# echo $(COMPILE)
# echo "\n\n"
# cc $(COMPILE) 
# ./testsample
	cc $(FULLPATH_SRCGETTESTRES) $(FULLPATH_SRCTESTUTILS) -L. $(NAME) -I. -o $(PATHTOGETTESTRES)a.out
	$(PATHTOGETTESTRES)a.out
	# cat $(PATHTOGETTESTRES)test_res.txt
	echo number of lines:
	cat $(PATHTOGETTESTRES)test_res.txt | wc -l
	cc $(FULLPATH_SRCREADTESTRES) $(FULLPATH_SRCTESTUTILS) -L. $(NAME) -I. -o $(PATHTOGETTESTRES)a.out
	$(PATHTOGETTESTRES)a.out
	
# cc -Wall -Wextra -Werror $test_file_name "test_util.c" -lbsd -o test -L. "$rel_path_to_project/libft.a"



OBJ = $(SRC:.c=.o)
# RESULTS = $(patsubst $(PATHTEST)%.c, $(PATHRESULTS)%.txt,$(SRCTEST))	
	
# $(PATHRESULTS)%.txt: $(PATHBUILD)%.a
#     -./$< > $@ 2>&1

all: $(NAME) libft

# test: $(BUILD_PATHS) $(RESULTS)
# 	@echo "-----------------------\nIGNORES:\n-----------------------"
# 	# @echo `grep -s IGNORE $(PATHRESULTS)*.txt`
# 	@echo "-----------------------\nFAILURES:\n-----------------------"
# 	# @echo `grep -s FAIL $(PATHRESULTS)*.txt`
# 	@echo "\nDONE"

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

libft:
	make -C libft
	cp $(PATHLIBFT) $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C libft clean
	
fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

print:
	@echo "compile flags: $(CFLAGS)"
	@echo "library name: $(NAME)"
	@echo "path to libft: $(PATHLIBFT)"
	@echo "path to unity: $(PATHUNITY)"
	@echo "path to test files: $(PATHTEST)"
	@echo "SRC: $(SRC)"
	@echo "SRCTEST: $(SRCTEST)"
	@echo "RESULTS: $(RESULTS)"


.PHONY: all clean fclean re libft test

