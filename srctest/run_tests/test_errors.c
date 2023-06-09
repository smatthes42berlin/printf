/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:22 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 13:13:57 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_printf.h"

void	test_errors(int fd)
{
	char *message = "errors testing";

	run_test(fd, message, "%s");
	return ;
}