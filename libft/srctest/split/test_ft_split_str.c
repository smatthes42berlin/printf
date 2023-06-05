/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:02:08 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/05 21:59:16 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/libft.h"
#include "../../src/split/ft_split_str.c"
#include "../test_libft.h"

void	setUp(void){};
void	tearDown(void){};

void	invalid_input(void)
{
	TEST_ASSERT_NULL(ft_split_str(NULL, "abc"));
	TEST_ASSERT_NULL(ft_split_str(NULL, NULL));
	TEST_ASSERT_NULL(ft_split_str("abc", NULL));
	TEST_ASSERT_NULL(ft_split_str("", NULL));
	TEST_ASSERT_NULL(ft_split_str(NULL, ""));
}

void	empty_string_helper(char const *s, char const *split_at)
{
	char	*actual[1];
	char	**test;

	actual[0] = "";
	test = ft_split_str(s, split_at);
	TEST_ASSERT_EQUAL_STRING_ARRAY(test, actual, 1);
	free(test);
}

void	empty_string(void)
{
	empty_string_helper("", "");
	empty_string_helper("", "aa");
	empty_string_helper("aaa", "aaa");
	empty_string_helper("aaaaaa", "aaa");
	empty_string_helper("aaaaaaaaaaaaaaa", "aaa");
}

void	valid_input_helper(char const *s, char const *split_at, char **actual,
		int num_elem)
{
	char	**test;

	test = ft_split_str(s, split_at);
	TEST_ASSERT_EQUAL_STRING_ARRAY(test, actual, num_elem);
	free(test);
}

void	valid_input(void)
{
	char	*actual[5];

	actual[0] = "aa";
	actual[1] = "aa";
	actual[2] = "aa";
	valid_input_helper("aabbaabbaa", "bb", actual, 3);
	valid_input_helper("bbaabbaabbaa", "bb", actual, 3);
	valid_input_helper("aabbaabbaabb", "bb", actual, 3);
	valid_input_helper("bbaabbaabbaabb", "bb", actual, 3);
	actual[0] = "aa";
	actual[1] = "baa";
	actual[2] = "baa";
	actual[3] = "b";
	valid_input_helper("aabbbaabbbaabbb", "bb", actual, 4);
	actual[0] = "aa";
	actual[1] = "baa";
	actual[2] = "baa";
	valid_input_helper("aabbbaabbbaabbbbbbbbbb", "bb", actual, 4);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(invalid_input);
	RUN_TEST(empty_string);
	RUN_TEST(valid_input);
	UNITY_END();
	return (0);
}
