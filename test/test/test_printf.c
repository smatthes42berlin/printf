/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:12 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/28 10:44:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test/unity/src/unity.h"

void	setUp(void){};
void	tearDown(void){};

void	test_should_return_five(void)
{
	TEST_ASSERT_EQUAL_INT(5, ft_test());
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_should_return_five);
	return (UNITY_END());
}