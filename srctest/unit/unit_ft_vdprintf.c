/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_ft_vdprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:40:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 17:05:20 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"
#include "./test_printf.h"

void	setUp(void){};
void	tearDown(void){};

void	test(void)
{
	TEST_ASSERT_EQUAL_STRING("", "");
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test);
	UNITY_END();
	return (0);
}
