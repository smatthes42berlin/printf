/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:48:30 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/28 18:22:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test/test_libftprintf.h"


void	test_single_c(int fd)
{
	int i = 32;
	while (i <= 127)
	{
		run_test(fd, "%c", i);
		i++;
	}
	return ;
}