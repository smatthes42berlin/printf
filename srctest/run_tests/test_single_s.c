/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:22 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/23 11:08:29 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_printf.h"

void	test_single_s(int fd)
{
	char *message = "single string testing";
	run_test(fd, message, "%s", "");
	run_test(fd, message, "%s", NULL);
	run_test(fd, message, "%s", "123");
	run_test(fd, message, "%s", "abc");
	run_test(fd, message, "%s", "OCTAL\001\013\177");
	return ;
}