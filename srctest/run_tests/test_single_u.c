/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:32 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/26 09:50:49 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_ft_printf.h"

void	test_single_u(int fd)
{
	char *message = "single unsigned decimal testing";

	run_test(fd, message, "%u", 0);
	run_test(fd, message, "%u", UINT_MAX);
	return ;
}