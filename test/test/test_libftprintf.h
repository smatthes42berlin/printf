/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libftprintf.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:00:22 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/29 08:20:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIBFTPRINTF_H
# define TEST_LIBFTPRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/* test controller */

void		run_test(int fd, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list args);
int			test_printf(void);

/* file handling */

FILE		*open_file(char *file_path, char *mode);
FILE		*open_file_stdout(char *file_path, char *mode);
int			close_file(FILE *fptr);
size_t		get_file_content(char *str, int size, size_t nmemb, FILE *fptr);
long		get_file_size(char *filename);
int			open_file_fd(char *file_path, int mode);
int			close_file_fd(int fd);

/* running tests */

void		run_all_tests(int fd);
void		test_single_c(int fd);
void		test_single_d(int fd);
void		test_single_i(int fd);
void		test_single_p(int fd);
void		test_single_s(int fd);
void		test_single_u(int fd);
void		test_single_x(int fd);
void		test_single_X(int fd);
void		test_single_gen(int fd);
void		test_comb(int fd);

/* reading file */

typedef struct s_tres_pf
{
	char	*print_is;
	char	*print_should;
	int		return_is;
	int		return_should;
}			tres_pf;

#endif