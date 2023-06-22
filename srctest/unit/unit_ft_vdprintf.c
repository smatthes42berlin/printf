/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_ft_vdprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:40:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/22 11:48:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"
#include "./test_printf.h"
#include "ft_vdprintf.c"
#include "ft_printf.c"

// static void	handle_specifiers(int fd, const char *cur_format,
// 		ssize_t *spec_chars_written, va_list args)

void	setUp(void){};
void	tearDown(void){};

void	va_arg_helper(int *spec_chars_written, const char *cur_format, ...);

void	va_arg_helper(int *spec_chars_written, const char *cur_format, ...)
{
	va_list	args;
	int		fd;

	fd = 1;
	va_start(args, cur_format);
	handle_specifiers(fd, cur_format, spec_chars_written, args);
	va_end(args);
}

void	one_char(void)
{
	int		spec_chars_written;
	const char	*cur_format;

	cur_format = "%c";
	spec_chars_written = 0;
	// TEST_ASSERT_EQUAL_STRING("", "");
	va_arg_helper(&spec_chars_written, cur_format, 'c');
	printf("\n\nspec chars is %d\n\n", spec_chars_written);
}

int	main(void)
{
	int return_val;
	return_val = ft_printf("%c", 'c');
	printf("\nreturn value is %d\n\n", return_val);
	return_val = ft_printf("%s", "\n\nHELLO WORLD!\n\n");
	printf("\nreturn value is %d\n\n", return_val);
	return (0);
}

