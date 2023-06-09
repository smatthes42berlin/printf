/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:14 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 13:15:53 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_printf.h"

void	test_single_p(int fd)
{
	char *message = "single pointer testing";
	run_test(fd, message, "%p", UINTPTR_MAX);
	run_test(fd, message, "%p", 0);
	run_test(fd, message, "%p", INTPTR_MAX);
	run_test(fd, message, "%p", INTPTR_MIN);
	return ;
}