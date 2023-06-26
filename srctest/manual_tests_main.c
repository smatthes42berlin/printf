/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:39:38 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/26 09:45:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/src/arr/ft_arr_set_int.c"
#include "../libft/src/io/ft_putchar_fd.c"
#include "../libft/src/io/ft_putchar_fd_len.c"
#include "../libft/src/io/ft_putnbr_base_check.c"
#include "../libft/src/io/ft_putnbr_base_fd_l.c"
#include "../libft/src/io/ft_putnbr_base_fd_ul.c"
#include "../libft/src/io/ft_putstr_fd_len.c"
#include "../libft/src/str/ft_str_cont_chars.c"
#include "../libft/src/str/ft_str_cont_duplic.c"
#include "../libft/src/str/ft_strchr.c"
#include "../libft/src/str/ft_strlen.c"
#include "./ft_printf.h"
#include "./ft_vdprintf.c"
#include "./ft_printf.c"
#include "./handle_c.c"
#include "./handle_p.c"
#include "./handle_s.c"
#include "./handle_d_i.c"
#include <stdint.h>

int	main(void)
{
	ft_printf("\nmy = $%d$\n", INT_MIN);
	printf("\nreal = $%d$\n\n", INT_MIN);
	ft_printf("\nmy = $%d$\n", -1);
	printf("\nreal = $%d$\n\n", -1);
	ft_printf("\nmy = $%d$\n", -132456);
	printf("\nreal = $%d$\n\n", -132456);
	printf("\ncasting = %ld\n", (long)INT_MIN);
}
