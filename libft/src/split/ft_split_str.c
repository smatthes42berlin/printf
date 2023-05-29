/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:05:46 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/29 16:29:54 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libft.h"


char	**ft_split_str(char const *s, char const *split_at)
{
	char	**test;

	test = NULL;
	// check for empty string here

	if (!s || !split_at)
		return (test);
	// write(1, s, 1);
	// write(1, split_at, 1);
	return (test);
}

// int main(void){
// 	char **res = ft_split_str("", "");
// 	printf("%p", res);
// }