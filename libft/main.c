/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:29:24 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/02 15:09:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libft.h"
#include <stdio.h>
#include "./src/split/ft_split_str.c"


int	main(void)
{
	// const char *str = "aaabbaaabbaaabb";
	// const char *split_at = "bb";
	// printf("str is \t\t$%s$\nsplit_at is \t$%s$\n", str, split_at);
	// ft_split_str(str, split_at);
	// ft_split_str("aabbaabbaa", "bb");
	// ft_split_str("", "bb");
	size_t test = calc_num_substr("bbbbbb", "bb");
    printf("%lu\n", test);
	// ft_split_str("bbbbbbb", "bb");
	// ft_split_str("bbbbbbaabbaabbaa", "bb");
	// ft_split_str("bbbbbbaabbaabbaabbbb", "bb");
	// ft_split_str("bbbbbbaabbaabbaabbbb", "bb");
}