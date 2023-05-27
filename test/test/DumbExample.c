/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DumbExample.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:07:45 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/27 10:07:47 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DumbExample.h"

int8_t	AverageThreeBytes(int8_t a, int8_t b, int8_t c)
{
	return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}