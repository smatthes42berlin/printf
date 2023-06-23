/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_l.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:24:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/23 16:31:50 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "../str/ft_strlen.c"
// #include "../str/ft_str_cont_chars.c"
// #include "../str/ft_str_cont_duplic.c"
// #include "../str/ft_strchr.c"
// #include "../arr/ft_arr_set_int.c"
// #include "./ft_putchar_fd_len.c"
// #include "./ft_putnbr_base_check.c"

static void	put_character(int fd, long nbr, t_base_info base_info,
				size_t *chars_printed);
static void	handle_long_min(int fd, size_t *chars_printed,
				t_base_info base_info);

size_t	ft_putnbr_base_fd_l(int fd, long nbr, const char *base)
{
	t_base_info	base_info;
	size_t		chars_printed;

	chars_printed = 0;
	if (!ft_putnbr_base_check(base, &base_info))
		return (0);
	if (nbr == LONG_MIN)
		handle_long_min(fd, &chars_printed, base_info);
	else
	{
		if (nbr < 0)
		{
			chars_printed += ft_putchar_fd_len('-', fd);
			nbr = nbr * -1;
		}
		put_character(fd, nbr, base_info, &chars_printed);
	}
	return (chars_printed);
}

static void	handle_long_min(int fd, size_t *chars_printed,
		t_base_info base_info)
{
	*chars_printed += ft_putnbr_base_fd_l(fd, LONG_MIN
			/ (long)base_info.base_len, base_info.base);
	*chars_printed += ft_putnbr_base_fd_l(fd, LONG_MIN
			% ((long)base_info.base_len) * -1, base_info.base);
}

void	put_character(int fd, long nbr, t_base_info base_info,
		size_t *chars_printed)
{
	long	base_index;
	long	num_div;

	if (nbr < (long)base_info.base_len)
	{
		*chars_printed += ft_putchar_fd_len(base_info.base[nbr], fd);
	}
	else
	{
		base_index = nbr % (long)base_info.base_len;
		num_div = nbr / base_info.base_len;
		put_character(fd, num_div, base_info, chars_printed);
		*chars_printed += ft_putchar_fd_len(base_info.base[base_index], fd);
	}
}

// int main (void){
// 	ft_putnbr_base_fd_l(1, LONG_MIN, "0123456789");
// 	printf("\n\n");
// 	ft_putnbr_base_fd_l(1, LONG_MIN, "01");
// 	printf("\n\n");
// 	ft_putnbr_base_fd_l(1, LONG_MIN, "0123456789ABCDEF");
// 	printf("\n\n");
// }