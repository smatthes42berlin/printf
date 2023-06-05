/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:05:46 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/05 22:03:10 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/libft.h"
#include <stdio.h>

static size_t	calc_num_substr(char const *s, char const *split_at,
					size_t *num_substr, int i);
// static int		get_substr_len(char const *s, char c);
// static int		create_sub_str(char **res, char const *s, char c);
static int		split_at_occurs(char const *str, char const *split_at,
					size_t split_at_length);

char	**ft_split_str(char const *s, char const *split_at)
{
	char	**res;
	size_t	num_substr;

	res = NULL;
	num_substr = 0;
	if (!s || !split_at)
		return (res);
	calc_num_substr(s, split_at, &num_substr, 0);
	printf("num substr = %zu\n\n", num_substr);
	// res = malloc(sizeof(*res) * (num_substr + 1));
	// if (!res)
	// 	return (NULL);
	// if (!create_sub_str(res, s, c))
	// 	return (NULL);
	// res[num_substr] = NULL;
	return (res);
}

// static int	create_sub_str(char **res, char const *s, char c)
// {
// 	int		i_str;
// 	size_t	i_num_substr;
// 	size_t	substr_len;

// 	i_str = 0;
// 	i_num_substr = 0;
// 	while (s[i_str])
// 	{
// 		if (s[i_str] != c)
// 		{
// 			substr_len = get_substr_len(s + i_str, c);
// 			if (!malloc_error_free(res, i_num_substr, substr_len))
// 				return (0);
// 			ft_strlcpy(res[i_num_substr], s + i_str, substr_len + 1);
// 			i_num_substr++;
// 			i_str += substr_len;
// 		}
// 		else
// 			i_str++;
// 	}
// 	return (1);
// }

// static int	get_substr_len(char const *s, char c)
// {
// 	int	len;

// 	len = 0;
// 	while (s[len] && s[len] != c)
// 		len++;
// 	return (len);
// }
static size_t	calc_num_substr(char const *s, char const *split_at,
		size_t *num_substr, int i)
{
	size_t	state;
	size_t	split_at_length;

	split_at_length = ft_strlen(split_at);
	state = 0;
	while (s[i])
	{
		while (s[i] && split_at_occurs(&s[i], split_at, split_at_length))
		{
			i += split_at_length;
			state = 0;
		}
		if (s[i])
		{
			i++;
			if (state == 0)
			{
				(*num_substr)++;
				state = 1;
			}
		}
	}
	return (*num_substr);
}

static int	split_at_occurs(char const *str, char const *split_at,
		size_t split_at_length)
{
	char	*sub_str;
	int		cmp_res;

	sub_str = ft_substr(str, 0, split_at_length);
	cmp_res = ft_strncmp(sub_str, split_at, split_at_length);
	if (cmp_res == 0)
		return (1);
	return (0);
}
