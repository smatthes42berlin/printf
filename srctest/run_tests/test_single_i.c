/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:06 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/25 17:00:52 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_ft_printf.h"

void	test_single_i(int fd)
{
	char *message = "single integer testing";
	run_test(fd,message, "%d", INT_MIN);
	run_test(fd,message, "%d", INT_MAX);
	run_test(fd,message, "%d", 0);
	run_test(fd,message, "%d", 123456);
	run_test(fd,message, "%d", -123456);
	return ;
}