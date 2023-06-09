/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:09 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/09 13:11:13 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./test_printf.h"

static t_res_pf	*check_results;
static size_t	i;
static void		test_case(void);
static int		last_test_reached(t_res_pf check_result);

void			setUp(void){};
void			tearDown(void){};

int	main(void)
{
	run_printf_test_to_file();
	check_results = read_test_results();
	UNITY_BEGIN();
	i = 0;
	while (!last_test_reached(check_results[i]))
	{
		RUN_TEST(test_case);
		i++;
	}
	UNITY_END();
	return (1);
}

void	test_case(void)
{
	TEST_ASSERT_EQUAL_STRING_MESSAGE(check_results[i].print_should,
										check_results[i].print_is,
										check_results[i].message);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(check_results[i].return_should,
										check_results[i].return_is,
										check_results[i].message);
}

int	last_test_reached(t_res_pf check_result)
{
	return (!check_result.print_is && !check_result.print_should
		&& !check_result.return_is && !check_result.return_should
		&& !check_result.message);
}
