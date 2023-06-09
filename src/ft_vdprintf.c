/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:15:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 16:23:23 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/src/libft.h"
#include "../printf.h"

static void	handle_specifiers(int fd, const char *cur_format,
				ssize_t *spec_chars_written, va_list args);

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	size_t	i;
	ssize_t	spec_chars_written;
	size_t	tot_write_count;

	i = 0;
	// attention
	// args++;
	// attention
	tot_write_count = 0;
	while (format[i])
	{
		handle_specifiers(fd, &format[i], &spec_chars_written, args);
		if (spec_chars_written > 0)
		{
			i += 2;
			tot_write_count += spec_chars_written;
		}
		if (spec_chars_written < 0)
		{
			i++;
			continue ;
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			tot_write_count += 1;
			i++;
		}
	}
	return (tot_write_count);
}

static void	handle_specifiers(int fd, const char *cur_format,
		ssize_t *spec_chars_written, va_list args)
{
	if (cur_format[0] != '%')
		*spec_chars_written = 0;
	else if (cur_format[1] == 'c')
		*spec_chars_written = (ssize_t)ft_putchar_fd_len(va_arg(args,
					unsigned int), fd);
	else if (cur_format[1] == 's')
		*spec_chars_written = (ssize_t)ft_putstr_fd_len(va_arg(args, char *),
				fd);
	else if (cur_format[1] == 'p')
		*spec_chars_written = 0;
	else if (cur_format[1] == 'd')
		*spec_chars_written = 0;
	else if (cur_format[1] == 'i')
		*spec_chars_written = 0;
	else if (cur_format[1] == 'u')
		*spec_chars_written = 0;
	else if (cur_format[1] == 'x')
		*spec_chars_written = 0;
	else if (cur_format[1] == 'X')
		*spec_chars_written = 0;
	else if (cur_format[1] == '%')
		*spec_chars_written = 0;
	else
		*spec_chars_written = -1;
}
