/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_ul.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:24:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/23 17:15:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../arr/ft_arr_set_int.c"
// #include "../str/ft_str_cont_chars.c"
// #include "../str/ft_str_cont_duplic.c"
// #include "../str/ft_strchr.c"
// #include "../str/ft_strlen.c"
// #include "./ft_putchar_fd_len.c"
// #include "./ft_putnbr_base_check.c"
#include "libft.h"

static void	put_character_ul(int fd, unsigned long nbr, t_base_info base_info,
				size_t *chars_printed);

size_t	ft_putnbr_base_fd_ul(int fd, unsigned long nbr, const char *base)
{
	t_base_info	base_info;
	size_t		chars_printed;

	chars_printed = 0;
	if (!ft_putnbr_base_check(base, &base_info))
		return (0);
	put_character_ul(fd, nbr, base_info, &chars_printed);
	return (chars_printed);
}

void	put_character_ul(int fd, unsigned long nbr, t_base_info base_info,
		size_t *chars_printed)
{
	long	base_index;
	long	num_div;

	if (nbr < (unsigned long)base_info.base_len)
	{
		*chars_printed += ft_putchar_fd_len(base_info.base[nbr], fd);
	}
	else
	{
		base_index = nbr % (unsigned long)base_info.base_len;
		num_div = nbr / base_info.base_len;
		put_character_ul(fd, num_div, base_info, chars_printed);
		*chars_printed += ft_putchar_fd_len(base_info.base[base_index], fd);
	}
}

// int	main(void)
// {
// 	size_t res;
// 	res = ft_putnbr_base_fd_ul(1, ULONG_MAX, "0123456789");
// 	printf("\n%ld\n", res);
// 	printf("\n\n");
// 	res = ft_putnbr_base_fd_ul(1, ULONG_MAX, "01");
// 	printf("\n%ld\n", res);
// 	printf("\n\n");
// 	res = ft_putnbr_base_fd_ul(1, ULONG_MAX, "0123456789ABCDEF");
// 	printf("\n%ld\n", res);
// 	printf("\n\n");
// }