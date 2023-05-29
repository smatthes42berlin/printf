/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:48:27 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/29 08:46:57 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test/test_libftprintf.h"

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	write(fd, "my_res", 6);
	return (6);
}

void	run_test(int fd, const char *format, ...)
{
	va_list	args;
	int		res_should;
	int		res_is;

	va_start(args, format);
	res_should = vdprintf(fd, format, args);
	dprintf(fd, "-*-*-");
	res_is = ft_vdprintf(fd, format, args);
	dprintf(fd, "-*-*-");
	dprintf(fd, "%d", res_is);
	dprintf(fd, "-*-*-");
	dprintf(fd, "%d", res_should);
	dprintf(fd, "-*-*-\n");
	va_end(args);
}

int	test_printf(void)
{
	int		fd;
	int		close;
	char	*file_path;

	file_path = "./test/test/get_output/test_res.txt";
	fd = open_file_fd(file_path, O_WRONLY | O_CREAT | O_TRUNC);
	close = close_file_fd(fd);
	chmod(file_path, S_IRWXU | S_IRWXO | S_IRWXG);
	fd = open_file_fd(file_path, O_WRONLY | O_CREAT | O_TRUNC);
	if (!fd)
		return (0);
	run_all_tests(fd);
	close = close_file_fd(fd);
	if (!close)
		return (0);
	return (1);
}
