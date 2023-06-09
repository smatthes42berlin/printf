/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 16:09:04 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vdprintf(1, format, args);
	va_end(args);
	return (1);
}
