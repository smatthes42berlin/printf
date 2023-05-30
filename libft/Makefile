# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/05/30 19:22:01 by smatthes         ###   ########.fr        #
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

PATHSRC = src/ src/split/
PATHBUILD = build/
PATHOBJ = build/objs/
PATHRES = build/results/
PATHUNITY = unity/src/unity.c
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

VPATH = $(PATHSRC) $(PATHTEST)

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
RESULTS = $(patsubst $(PATHTEST)%.c,$(PATHRES)%.txt,$(SRCTESTFNAME) )


$(info $$var is 1 [${RESULTS}])

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(PATHOBJ)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`

test: $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATHB)test_%.$(TARGET_EXTENSION): $(PATHO)test_%.o $(PATHO)%.o $(PATHO)unity.o
	$(LINK) -o $@ $^

$(PATHO)%.o:: %.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: %.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHU)%.c $(PATHU)%.h
	$(COMPILE) $(CFLAGS) $< -o $@



	
	