# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/05/25 10:07:42 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCCORE = ft_atoi.c ft_isdigit.c ft_memmove.c \
ft_split.c ft_strlcat.c ft_strrchr.c \
ft_bzero.c ft_isprint.c ft_memset.c \
ft_strlcpy.c ft_strtrim.c ft_strnstr.c \
ft_calloc.c ft_itoa.c ft_putchar_fd.c \
ft_strchr.c ft_strlen.c ft_substr.c \
ft_isalnum.c ft_memchr.c ft_putendl_fd.c \
ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c \
ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_isascii.c ft_memcpy.c ft_putstr_fd.c \
ft_strjoin.c

SRCBONUS =	ft_lstadd_back.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c \
ft_lstsize.c ft_lstadd_front.c \
ft_lstdelone.c ft_lstlast.c \
ft_lstnew.c

OBJSCORE = $(SRCCORE:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJSCORE)
	ar rcs $(NAME) $^

bonus: $(OBJSCORE) $(OBJBONUS)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJSCORE) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
