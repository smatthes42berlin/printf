/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:58:44 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/05 20:45:03 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIBFT_H
# define TEST_LIBFT_H

# include "../unity/src/unity.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>


#define CONC(macro,str) macro ## str

#define A "123/"
#define B "./456"
#define C "789"


#define AB A ## B
#define ABC AB ## C

#include ABC

// #define TEST CONC(PATH_SRC, ../src/)

#define PATH_SRC  "../src/"

#define PATH_ASCII  PATH_SRC ascii/ 
#define PATH_CONVERT  PATH_SRC convert/ 
#define PATH_IO  PATH_SRC io/ 
#define PATH_LST  PATH_SRC lst/ 
#define PATH_MEM  PATH_SRC mem/ 
#define PATH_SPLIT  PATH_SRC split/ 
#define PATH_STR  PATH_SRC ## "str/" 


#define PATH_ATOI PATH_CONVERT"ft_atoi.c"
#define PATH_ITOA PATH_CONVERT"ft_itoa.c"

#define PATH_ISDIGIT PATH_ASCII"ft_isdigit.c"
#define PATH_ISALNUM PATH_ASCII"ft_isalnum.c"
#define PATH_ISPRINT PATH_ASCII"ft_isprint.c"
#define PATH_ISASCII PATH_ASCII"ft_isascii.c"
#define PATH_TOUPPER PATH_ASCII"ft_toupper.c"
#define PATH_TOLOWER PATH_ASCII"ft_tolower.c"
#define PATH_ISALPHA PATH_ASCII"ft_isalpha.c"

#define PATH_SPLIT PATH_SPLIT"ft_split.c"
#define PATH_SPLIT_STR PATH_SPLIT"ft_split_str.c"
#define PATH_SPLIT_STR_FREE_ERROR PATH_SPLIT"ft_split_free_error.c"

#define PATH_MEMOVE PATH_MEM"ft_memmove.c"
#define PATH_MEMCHR PATH_MEM"ft_memchr.c"
#define PATH_MEMSET PATH_MEM"ft_memset.c"
#define PATH_MEMCMP PATH_MEM"ft_memcmp.c"
#define PATH_MEMCPY PATH_MEM"ft_memcpy.c"
#define PATH_BZERO PATH_MEM"ft_bzero.c"
#define PATH_CALLOC PATH_MEM"ft_calloc.c"

#define PATH_PUTCHAR_FD PATH_IO"ft_putchar_fd.c"
#define PATH_PUTENDL_FD PATH_IO"ft_putendl_fd.c"
#define PATH_PUTNBR_FD PATH_IO"ft_putnbr_fd.c"
#define PATH_PUTSTR_FD PATH_IO"ft_putstr_fd.c"

#define PATH_STRLCAT PATH_STR"ft_strlcat.c"
#define PATH_STRRCHR PATH_STR"ft_strrchr.c"
#define PATH_STRLCPY PATH_STR"ft_strlcpy.c"
#define PATH_STRTRIM PATH_STR"ft_strtrim.c"
#define PATH_STRNSTR PATH_STR"ft_strnstr.c"
#define PATH_STRCHR PATH_STR"ft_strchr.c"
#define PATH_STRLEN PATH_STR"ft_strlen.c"
#define PATH_SUBSTR PATH_STR"ft_substr.c"
#define PATH_STRDUP PATH_STR ## ft_strdup.c
#define PATH_STRMAPI PATH_STR"ft_strmapi.c"
#define PATH_STRITERI PATH_STR"ft_striteri.c"
#define PATH_STRNCMP PATH_STR"ft_strncmp.c"
#define PATH_STRJOIN PATH_STR"ft_strjoin.c"

#define PATH_LSTADD_BACK PATH_LST"ft_lstadd_back.c"
#define PATH_LSTCLEAR PATH_LST"ft_lstclear.c"
#define PATH_LSTITER PATH_LST"ft_lstiter.c"
#define PATH_LSTMAP PATH_LST"ft_lstmap.c"
#define PATH_LSTSIZE PATH_LST"ft_lstsize.c"
#define PATH_LSTADD_FRONT PATH_LST"ft_lstadd_front.c"
#define PATH_LSTDELONE PATH_LST"ft_lstdelone.c"
#define PATH_LSTLAST PATH_LST"ft_lstlast.c"
#define PATH_LSTNEW PATH_LST"ft_lstnew.c" 

#endif