/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_set_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:31:05 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/26 11:34:33 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_arr_set_int(int *arr, size_t size, int num)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		arr[i] = num;
		i++;
	}
	return (i);
}
