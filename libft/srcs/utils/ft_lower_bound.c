/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_bound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:57:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 23:56:09 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lower_bound(int arr[], size_t size, int target)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = size;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}
