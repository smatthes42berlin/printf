/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 13:16:14 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_printf.h"

void	test_single_percent(int fd)
{
	char *message = "single percent sign testing";

	run_test(fd, message, "%%");
	return ;
}