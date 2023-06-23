/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:45 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/23 14:35:21 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_vdprintf(int fd, const char *format, va_list args);
int		ft_printf(const char *format, ...);
size_t	handle_p(int fd, va_list args);
size_t	handle_c(int fd, va_list args);

#endif