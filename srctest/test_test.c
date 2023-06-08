/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:09 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/08 15:28:28 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libftprintf.h"
#include <stdio.h>

int	main(void)
{
	t_res_pf *check_results;

	run_printf_test_to_file();
	check_results = read_test_results();
	printf("\n\n\nHi there \n\n\n");
	// printf("%c", file_content[7]);
	check_results++;
	return (1);
}