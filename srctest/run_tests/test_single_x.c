/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:41 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/25 17:00:52 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_ft_printf.h"

void	test_single_x(int fd)
{
	char *message = "single small hexadecimal testing";

	run_test(fd, message, "%x", UINTPTR_MAX);
	run_test(fd, message, "%x", INTPTR_MAX);
	run_test(fd, message, "%x", INTPTR_MIN);
	run_test(fd, message, "%x", 0);
	return ;
}