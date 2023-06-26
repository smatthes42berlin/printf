/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:49:45 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/26 08:43:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_ft_printf.h"

void	test_single_d(int fd)
{
	char *message = "single char testing";
	run_test(fd, message, "%d", INT_MIN);
	run_test(fd, message, "%d", INT_MAX);
	run_test(fd, message, "%d", 0);
	run_test(fd, message, "%d", -1);
	run_test(fd, message, "%d", 1);
	return ;
}