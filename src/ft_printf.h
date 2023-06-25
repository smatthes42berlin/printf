/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:45 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/25 16:25:46 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_vdprintf(int fd, const char *format, va_list args);
int		ft_printf(const char *format, ...);
size_t	handle_p(int fd, va_list args);
size_t	handle_c(int fd, va_list args);
size_t	handle_s(int fd, va_list args);

#endif