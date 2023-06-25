/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:14 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/25 17:00:52 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_ft_printf.h"

void	test_single_p(int fd)
{
	run_test(fd, "single pointer testing 1", "%p", UINTPTR_MAX);
	run_test(fd, "single pointer testing 2", "%p", 0);
	run_test(fd, "single pointer testing 3", "%p", INTPTR_MAX);
	run_test(fd, "single pointer testing 4", "%p", INTPTR_MIN);
	return ;
}