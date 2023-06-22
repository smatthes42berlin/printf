/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:24:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/22 18:05:28 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_base_fd(int fd, int nbr, const char *base)
{
	size_t	base_len;
	long	nbr_l;

	nbr_l = (long)nbr;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (-1);
	if (ft_str_cont_chars(base, "+-"))
		return (-1);
	if (ft_str_cont_duplic(base))
		return (-1);
	if (nbr_l < 0)
	{
		ft_putchar_fd('-', fd);
		nbr_l = nbr_l * -1;		
	}
	fd++;
	nbr++;
	base++;
	return (1);
	// ft_putchar_fd_len(fd);
	// ft_putstr_fd_len("str", fd);
}
