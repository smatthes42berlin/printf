# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/06/01 19:11:58 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite

# make library
# compile each test together with library
SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a
TARGET_EXTENSION=out
LINK= cc
CC = cc

PATHSRC = src/ src/split/
PATHBUILD = build/
PATHOBJ = build/obj/
PATHTESTEXE = build/exe/
PATHRES = build/results/
PATHUNITY = unity/src/
PATHTEST = srctest/ srctest/split/

SRCFNAMERELPATH = 	ft_atoi.c \
					ft_isdigit.c \
					ft_memmove.c \
					split/ft_split.c \
					split/ft_split_str.c \
					split/ft_split_free_error.c \
					ft_strlcat.c \
					ft_strrchr.c \
					ft_bzero.c \
					ft_isprint.c \
					ft_memset.c \
					ft_strlcpy.c \
					ft_strtrim.c \
					ft_strnstr.c \
					ft_calloc.c \
					ft_itoa.c \
					ft_putchar_fd.c \
					ft_strchr.c \
					ft_strlen.c \
					ft_substr.c \
					ft_isalnum.c \
					ft_memchr.c \
					ft_putendl_fd.c \
					ft_strdup.c \
					ft_strmapi.c \
					ft_tolower.c \
					ft_isalpha.c \
					ft_memcmp.c \
					ft_putnbr_fd.c \
					ft_striteri.c \
					ft_strncmp.c \
					ft_toupper.c \
					ft_isascii.c \
					ft_memcpy.c \
					ft_putstr_fd.c \
					ft_strjoin.c \
					ft_lstadd_back.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstsize.c \
					ft_lstadd_front.c \
					ft_lstdelone.c \
					ft_lstlast.c \
					ft_lstnew.c \

VPATH = $(PATHSRC) $(PATHTEST) $(PATHUNITY)

SRCFNAME = 	$(notdir $(SRCFNAMERELPATH))
SRC = $(patsubst %,$(PATHSRC)%,$(SRCFNAMERELPATH))

SRCTESTFNAMERELPATH = 	split/test_ft_split_str.c 

SRCTESTFNAME = 	$(notdir $(SRCTESTFNAMERELPATH))
SRCTEST = $(patsubst %,$(PATHSRC)%,$(SRCTESTFNAMERELPATH))

OBJFNAME = $(SRCFNAME:.c=.o)
OBJ = $(patsubst %,$(PATHOBJ)%,$(OBJFNAME))

OBJTESTFNAME = $(SRCTESTFNAME:.c=.o)
OBJTEST = $(patsubst %,$(PATHOBJ)%,$(OBJTESTFNAME))

RESULTS = $(patsubst %.c,$(PATHRES)%.txt,$(SRCTESTFNAME) )
TESTEXE = $(patsubst %.c,$(PATHTESTEXE)%.$(TARGET_EXTENSION),$(SRCTESTFNAME) )

PASSED = `grep -s PASS $(PATHRES)*.txt`
FAIL = `grep -s FAIL $(PATHRES)*.txt`
IGNORE = `grep -s IGNORE $(PATHRES)*.txt`

.PHONY: all clean fclean re bonus test print

test: $(RESULTS) 
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

$(PATHRES)%.txt: $(PATHTESTEXE)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATHTESTEXE)test_%.$(TARGET_EXTENSION): $(PATHOBJ)test_%.o $(PATHOBJ)%.o $(PATHOBJ)unity.o
	$(LINK) -o $@ $^

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(PATHOBJ)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJTEST)
	$(RM) $(RESULTS)
	$(RM) $(TESTEXE)
	$(RM) $(PATHOBJ)unity.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PRECIOUS: $(PATHTESTEXE)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHOBJ)%.o
.PRECIOUS: $(PATHRES)%.txt	

INDENTATION = 15
INDENTATION2 = 30
HEADINGFORMATBEG = *****************************************
HEADINGFORMATEND = $(HEADINGFORMATBEG)

define print_file_names
	@for a in $(1) ; do \
		c=$$(( $${c:--1}+1 )); \
    	if [[ $$(($$c % 4)) == 0 ]]; then \
    	 	printf "\n"; \
		fi; \
			printf "%-$(INDENTATION2)s" $$a; \
    done
    @printf "\n";
endef 

define print_path_var 
	@printf "%-$(INDENTATION)s %-$(INDENTATION)s" $(1) $(2)
	@printf "\n"
endef

define print_heading
	@printf "\n$(HEADINGFORMATBEG)$(1)$(HEADINGFORMATEND)\n"
endef

print:
	@clear
	$(call print_heading, PATH)
	$(call print_path_var, PATHSRC, $(PATHSRC))
	$(call print_path_var, PATHBUILD, $(PATHBUILD))
	$(call print_path_var, PATHOBJ, $(PATHOBJ))
	$(call print_path_var, PATHTESTEXE, $(PATHTESTEXE))
	$(call print_path_var, PATHRES, $(PATHRES))
	$(call print_path_var, PATHUNITY, $(PATHUNITY))
	$(call print_path_var, PATHTEST, $(PATHTEST))
	$(call print_path_var, VPATH, $(VPATH))
	$(call print_heading, SRC FILES)
	$(call print_file_names, $(SRCFNAMERELPATH))
	$(call print_heading, SRC TEST FILES)
	$(call print_file_names, $(SRCTESTFNAMERELPATH))
	$(call print_heading, OBJ)
	$(call print_file_names, $(OBJFNAME))
	$(call print_heading, OBJTEST)
	$(call print_file_names, $(OBJTESTFNAME))
	$(call print_heading, RESULTS)
	$(call print_file_names, $(RESULTS))
