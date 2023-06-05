/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_ft_split_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:27:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/05 22:00:05 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_libft.h"
#include "ft_split_str.c"
#include "ft_strdup.c"
#include "ft_strlcpy.c"
#include "ft_strlen.c"
#include "ft_strncmp.c"
#include "ft_substr.c"

void	setUp(void){};
void	tearDown(void){};

void	num_substr(void)
{
	size_t	num_substr;

	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("aabbaabbaa", "bb",
				&num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(0, calc_num_substr("", "bb", &num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(0, calc_num_substr("bbbbbb", "bb", &num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(1, calc_num_substr("bbbbbbb", "bb", &num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("bbbbbbaabbaabbaa", "bb",
				&num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("bbbbbbaabbaabbaabbbb", "bb",
				&num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("aabbaabbaabbbbbb", "bb",
				&num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("aabbaabbabbbbbb", "bb",
				&num_substr, 0));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("abbabbabbbbbb", "bb",
				&num_substr, 0));
	num_substr = 0;
};
int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(num_substr);
	UNITY_END();
	return (0);
}
