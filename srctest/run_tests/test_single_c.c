/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:48:30 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 13:14:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_printf.h"

void	test_single_c(int fd)
{
	char *message = "single char testing";

	run_test(fd, message, "%c", 32);
	run_test(fd, message, "%c", 126);
	run_test(fd, message, "%c", 48);
	run_test(fd, message, "%c", 93);
	return ;
}