/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_in_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:06:52 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:34:39 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_in_array(int *arr, size_t size, int value)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if (arr[i] == value)
			return (TRUE);
	return (FALSE);
}
