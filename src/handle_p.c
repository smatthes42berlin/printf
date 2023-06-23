/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:39:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/23 15:21:46 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/src/libft.h"
#include "../printf.h"

size_t	handle_p(int fd, va_list args)
{
	char			*base;
	unsigned long	ptr_l;
	size_t			chars_written;

	base = "0123456789abcdef";
	ptr_l = va_arg(args, unsigned long);
	printf("value = %lu\n\n", ptr_l);
	printf("value = %lu\n\n", ptr_l);
	if (ptr_l == 0)
		chars_written = ft_putstr_fd_len("(nil)", fd);
	else
	{
		chars_written = ft_putstr_fd_len("0x", fd);
		chars_written += ft_putnbr_base_fd_l(fd, ptr_l, base);
	}
	return (chars_written);
}
