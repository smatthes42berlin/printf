/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:39:42 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/26 09:48:36 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

size_t	handle_d_i(int fd, va_list args)
{
	char	*base;
	long	nbr;

	nbr = (long)va_arg(args, int);
	base = "0123456789";
	return (ft_putnbr_base_fd_l(fd, nbr, base));
}
