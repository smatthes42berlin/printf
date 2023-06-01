# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/06/01 13:13:19 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite

# make library
# compile each test together with library

CFLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a
NAMETEST = test.a
TARGET_EXTENSION=out

PATHSRC = src/ src/split/
PATHBUILD = build/
PATHOBJ = build/obj/
PATHTESTEXE = build/exe/
PATHRES = build/results/
PATHUNITY = unity/src/
PATHTEST = test/ test/split/

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

$(info $$var is 1 [${SRCTESTFNAME}])

$(info $$var is 1 [${VPATH}])

RESULTS = $(patsubst %.c,$(PATHRES)%.txt,$(SRCTESTFNAME) )
TESTEXE = $(patsubst %.c,$(PATHTESTEXE)%.$(TARGET_EXTENSION),$(SRCTESTFNAME) )
# RESULTS = $(patsubst $(PATHTEST)%.c,$(PATHRES)%.txt,$(SRCTESTFNAME) )
# RESULTS = $(patsubst %.c,%.txt,$(SRCTESTFNAME) )

$(info $$Path build [${TESTEXE}])


# CFLAGS= -Wall -Wextra -Werror -I. -I$(PATHUNITY) -I$(PATHSRC) -DTEST
CFLAGS= -Wall -Wextra -Werror -I.
COMPILE=cc -c
LINK=cc


PASSED = `grep -s PASS $(PATHRES)*.txt`
FAIL = `grep -s FAIL $(PATHRES)*.txt`
IGNORE = `grep -s IGNORE $(PATHRES)*.txt`

test: $(RESULTS) 
# test: build/results/test_ft_split_str.txt 
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

$(info $$Path build [${PATHBUILD}])
$(info $$Path res [${PATHRES}])
$(info $$Path obj [${PATHOBJ}])
$(info $$Path src [${PATHSRC}])
$(info $$Path src test [${PATHTEST}])
$(info $$Path unity [${PATHUNITY}])
$(info $$Results is [${RESULTS}])



#+++++++ writing explicitely


$(PATHRES)%.txt: $(PATHTESTEXE)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1


# build/results/test_ft_split_str.txt: build/exe/test_ft_split_str.out 
# 	-./$< > $@ 2>&1

# build/exe/test_ft_split_str.out: build/obj/test_ft_split_str.o build/obj/ft_split_str.o build/obj/unity.o
# 	$(LINK) -o $@ $^


# # build/obj/test_ft_split_str.o
# # build/obj/ft_split_str.o
# # build/obj/unity.o
# # test/test_ft_split_str.c test/split/test_ft_split_str.c
# # ft_split_str.c
# # unity.c



# build/obj/test_ft_split_str.o:: test_ft_split_str.c
# 	$(COMPILE) $(CFLAGS) $< -o $@

# build/obj/ft_split_str.o:: ft_split_str.c
# 	$(COMPILE) $(CFLAGS) $< -o $@

# build/obj/unity.o:: unity/src/unity.c unity/src/unity.h 
# 	$(COMPILE) $(CFLAGS) $< -o $@

# PATHTESTEXE

$(PATHTESTEXE)test_%.$(TARGET_EXTENSION): $(PATHOBJ)test_%.o $(PATHOBJ)%.o $(PATHOBJ)unity.o
	$(LINK) -o $@ $^


$(PATHOBJ)%.o:: %.c
	$(COMPILE) $(CFLAGS) $< -o $@


#+++++++

# see makefile manual vpath

# # build/results/test_ft_split_str.txt
# # build/test_ft_split_str.out
# $(PATHRES)%.txt: $(PATHBUILD)%.$(TARGET_EXTENSION)
# 	-./$< > $@ 2>&1

# # build/test_ft_split_str.out
# # build/obj/test_ft_split_str.o
# # build/obj/ft_split_str.o
# # build/obj/unity.o

# $(PATHBUILD)test_%.$(TARGET_EXTENSION): $(PATHOBJ)test_%.o $(PATHOBJ)%.o $(PATHOBJ)unity.o
# 	$(LINK) -o $@ $^

# # build/obj/test_ft_split_str.o
# # build/obj/ft_split_str.o
# # build/obj/unity.o
# # test/test_ft_split_str.c test/split/test_ft_split_str.c
# # ft_split_str.c
# # unity.c

# $(PATHOBJ)%.o:: $(PATHTEST)%.c
# 	$(COMPILE) $(CFLAGS) $< -o $@

# $(PATHOBJ)%.o:: $(PATHSRC)%.c
# 	$(COMPILE) $(CFLAGS) $< -o $@

# $(PATHOBJ)%.o:: $(PATHUNITY)%.c $(PATHUNITY)%.h
# 	$(COMPILE) $(CFLAGS) $< -o $@


# normal make

.PHONY: all clean fclean re bonus test

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
	