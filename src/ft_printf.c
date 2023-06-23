/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/23 15:21:31 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/src/arr/ft_arr_set_int.c"
#include "../libft/src/io/ft_putchar_fd.c"
#include "../libft/src/io/ft_putchar_fd_len.c"
#include "../libft/src/io/ft_putnbr_base_fd_l.c"
#include "../libft/src/io/ft_putstr_fd_len.c"
#include "../libft/src/str/ft_str_cont_chars.c"
#include "../libft/src/str/ft_str_cont_duplic.c"
#include "../libft/src/str/ft_strchr.c"
#include "../libft/src/str/ft_strlen.c"
#include "../printf.h"
#include "./ft_vdprintf.c"
#include "./handle_c.c"
#include "./handle_p.c"
#include <stdint.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vdprintf(1, format, args);
	va_end(args);
	return (1);
}

int	main(void)
{
	char	*ptr;

	ptr = "123";
	ft_printf("\nmy = $%p$\n", UINTPTR_MAX);
	printf("\nmy = $%ld$\n", UINTPTR_MAX);
	printf("\nreal = $%p$\n", UINTPTR_MAX);
	// ft_printf("my = $%p$", INTPTR_MAX);
	// printf("\n\n");
	// ft_printf("my = $%p$", INTPTR_MIN);
	// printf("\n\n");
	// printf("real = $%p$", ptr);
}
