# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/05/25 16:48:26 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite

# copy the file and rename it

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
PATHTOLIBFT = /libft/
PATHTOLIBFT2 = /libft/libft.a
LIBFTNAME = libft.a

SRCCORE = ft_test.c

OBJSCORE = $(SRCCORE:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJSCORE)
	ar rcs $(NAME) $^

libft123:
	$(cd libft)	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJSCORE) $(OBJBONUS)
	
	
fclean: clean
	$(RM) $(NAME)

re: fclean all
